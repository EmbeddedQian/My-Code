#include"stdafx.h"


using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
const int MALE = 1;
const int FEMALE = 0;

class MyTimer
{
public:
	MyTimer()
	{
		QueryPerformanceFrequency(&_freq);
		costTime = 0.0;
	}
	void Start()
	{
		for (int i = 0; i < EN_NUMER; ++i)
		{
			QueryPerformanceCounter(&_array[i]._begin);
		}
	}
	void Stop()
	{
		for (int i = 0; i < EN_NUMER; ++i)
		{
			QueryPerformanceCounter(&_array[i]._end);
		}
	}
	void Reset()
	{
		costTime = 0.0;
	}
	void showTime()
	{
		double allTime = 0.0;
		for (int i = 0; i < EN_NUMER; ++i)
		{
			allTime += (((double)_array[i]._end.QuadPart - (double)_array[i]._begin.QuadPart) / (double)_freq.QuadPart);
		}
		costTime = allTime / EN_NUMER;
		costTime *= 1000000;

		if ((((int)costTime) / 1000000) > 0)
		{
			cout << costTime / 1000000 << " s" << endl;
		}
		else if (((int)costTime) / 1000 > 0)
		{
			cout << costTime / 1000 << " ms" << endl;
		}
		else
		{
			cout << costTime << " us" << endl;
		}
	}
private:
	class Array
	{
	public:
		LARGE_INTEGER _begin;
		LARGE_INTEGER _end;
	};
	enum { EN_NUMER = 5 };
	LARGE_INTEGER _freq;
	double costTime;
	Array _array[EN_NUMER];
};
//=====================================================================================================
/* ��Ա������Ϣ */
class Person
{
public:
	Person() {}
	Person(int gender, int id, int look, int character, int treasure,
		int olook, int ocharacter, int otreasure)
		:mgender(gender), mid(id), mlook(look), mcharacter(character),
		mtreasure(treasure), molook(olook), mocharacter(ocharacter), motreasure(otreasure) {}

	int getId() { return mid; }
	int getLook() { return mlook; }
	int getCharacter() { return mcharacter; }
	int getTreasure() { return mtreasure; }

	int getOlook() { return molook; }
	int getOcharacter() { return mocharacter; }
	int getOtreasure() { return motreasure; }
	int getGender() { return mgender; }

	bool operator==(const Person& rhs)
	{
		return mid == rhs.mid;
	}

	bool operator<(const Person& rhs)const
	{
		return mid < rhs.mid;
	}
private:
	int mid; // ����id
	int mlook; // ������ò
	int mcharacter; // ����Ʒ��
	int mtreasure; // ���˲Ƹ�

	int molook; // ������ò
	int mocharacter; // ����Ʒ��
	int motreasure; // �����Ƹ�
	int mgender; // �����Ա�
};

//=====================================================================================================
/* ���ļ���ȡ����Ů����Ϣ���������Ϊ�Ա� */
vector<Person>getData(string file, int gender)
{
	vector<Person> vec;
	vec.reserve(100);
	int id, look, character, treasure, olook, ocharacter, otreasure;

	FILE* fp;
	fopen_s(&fp, file.c_str(), "r");
	assert(fp != 0);

	for (int i = 0; i < 100; ++i)
	{
		fscanf_s(fp, "%d,%d,%d,%d,%d,%d,%d", &id, &look, &character
			, &treasure, &olook, &ocharacter, &otreasure);
		Person per(gender, id, look, character, treasure, olook,
			ocharacter, otreasure);

		vec.emplace_back(per);
	}
	fclose(fp);
	return vec;
}

//=====================================================================================================
/* ���ļ���ȡ���ǵ���Ϣ���������id����Ϊ-1 */
vector<Person>getPlayerData(string file, int id)
{
	vector<Person> vec;
	vec.reserve(100);
	int gender, look, character, treasure, olook, ocharacter, otreasure;
	FILE* fp;
	fopen_s(&fp, file.c_str(), "r");
	assert(fp != 0);

	for (int i = 0; i < 100; ++i)
	{
		fscanf_s(fp, "%d,%d,%d,%d,%d,%d,%d", &gender, &look
			, &character, &treasure, &olook, &ocharacter, &otreasure);

		//ÿ��ѭ������һ��person����
		Person per(gender, id, look, character, treasure,
			olook, ocharacter, otreasure);

		vec.emplace_back(per);
	}
	fclose(fp);
	return vec;
}

//=====================================================================================================
/* ƥ����� */
class Calculate
{
private:

	vector<Person> female; // �洢Ů����Ϣ
	vector<Person> players; // �洢������Ϣ
	vector<Person> male; // �洢������Ϣ

	int msize; // ��ʼ�������ռ��С
	bool isExist; // ��־λ����־һ�������Ƿ�ѡ��
	int index; // �������

public:

	/* ��ʼ�� */
	Calculate(int size) :msize(size)
	{
		male = vector<Person>(size);
		female = vector<Person>(size);
		isExist = false; // ��־λ��Ϊfalse
		index = 0; // ���������ʼΪ0
	}

	void start()
	{
		vector<Person> maleData(getData("male.txt", MALE));
		vector<Person> femaleData(getData("female.txt", FEMALE));
		players = getPlayerData("players.txt", -1); // ����idΪ-1

													/* �����Ǽ��룬��ʼƥ�� */
		for (Person player : players)
		{
			/* �õ���Ů����Ϣ�ĸ��� */
			male.assign(maleData.begin(), maleData.end());
			female.assign(femaleData.begin(), femaleData.end());

			/* ���������Ա���뵽��Ӧ�Ķ����� */
			if (player.getGender() == MALE)
			{
				male.emplace_back(player);
			}
			else
			{
				female.emplace_back(player);
			}
			choiceFemale();
		}
	}

	/* ȫ��������ʼѡ����ʵ�Ů�� */
	void choiceFemale()
	{
		/* map�洢 <Ů���������б�> */
		map<Person, vector<Person>> hashMap;
		Person suit;



		for (Person per : male)
		{
			/* �õ�����ʵ�Ů�� */
			suit = satisfy(per, female);

			auto it = hashMap.find(suit);

			/* Ů���ѱ�ѡ��ֱ�Ӽ������б� */
			if (it != hashMap.end())
			{
				it->second.emplace_back(per);
			}
			/* Ů��û��ѡ����ֱ�Ӵ���map�洢 */
			else
			{
				vector<Person> maleList;
				maleList.emplace_back(per);
				hashMap.insert(pair<Person,
					vector<Person>>(suit, maleList));
			}
		}

		for (int i = 0; i < msize; i++)
		{
			/* �õ���ѡ����Ů�� */
			Person mFemale(invFemale(hashMap));

			/* Ů��ѡ������ʵ����� */
			vector<Person> maleList(choiceMale(mFemale, hashMap));

			/* ���س���Ϊ0����ʾ�����ѱ�ѡ�����ֽ��� */
			if (maleList.size() == 0)
			{
				break;
			}

			/* ���򣬿�ʼ�����������Ů���������б� */
			vector<Person>::iterator it = maleList.begin();
			while (it != maleList.end())
			{
				Person per(*it);

				// ͬ�ϣ���������ѡ���µ��������Ů��
				Person max_best(satisfy(per, female));
				auto it1 = hashMap.find(max_best);
				/* Ů���ѱ�ѡ��ֱ�Ӽ�������� */
				if (it1 != hashMap.end())
				{
					it1->second.emplace_back(per);
				}
				/* Ů��û��ѡ����ֱ�Ӵ���map�洢 */
				else
				{
					vector<Person> maleList;
					maleList.push_back(per);
					hashMap.insert(pair<Person,
						vector<Person>>(max_best, maleList));
				}
				++it;
			}
		}
		/* ������Ǳ���û�б�ѡ����ôplayer��ѡ��idΪĬ��ֵ-2������ӡ��Ϣ */
		if (!isExist)
		{
			cout << "��" << ++index << "��player���룺 " << endl;
		}
		/* �������Ǳ��ֱ�ѡ������־λ�û� */
		else
		{
			isExist = false;
		}
	}

	/* Ů��ѡ������ʵ����� */
	vector<Person> choiceMale(Person & mFemale, map<Person, vector<Person>> & hashmap)
	{
		/* �õ���Ů���������б� */
		vector<Person> maleList(hashmap[mFemale]);
		/* �õ���Ů������������� */
		Person suit(satisfy(mFemale, maleList));

		/* ������������ǣ���ƥ��ɹ���ֱ�Ӵ�ӡ */
		if (mFemale.getId() == -1 || suit.getId() == -1)
		{
			/*cout << mFemale.getId() << " : ";
			auto it1 = maleList.begin();
			while (it1 != maleList.end())
			{
			cout << (*it1).getId() << "  ";
			++it1;
			}
			cout << endl;*/

			isExist = true; // ��־λ��true

							/* ������������ǣ���ƥ��ɹ���ֱ�Ӵ�ӡ */
			if (mFemale.getId() == -1)
			{
				cout << "��" << ++index << "��player���룺"
					<< suit.getId() << ":" << "-1" << endl;
			}
			else
			{
				cout << "��" << ++index << "��player���룺"
					<< "-1" << ":" << mFemale.getId() << endl;
			}
			/* ���ؿ����� */
			return vector<Person>();
		}

		/*
		** ��ƥ��ɹ���һ����û�����ǣ���ô��male��
		** female������maleList�б���ɾ������
		*/
		auto it = find(male.begin(), male.end(), suit);
		male.erase(it);

		it = find(female.begin(), female.end(), mFemale);
		female.erase(it);

		it = find(maleList.begin(), maleList.end(), suit);
		maleList.erase(it);

		return maleList;
	}
	/* �õ���������Ů�� */
	Person invFemale(map<Person, vector<Person>> & hashmap)
	{
		unsigned int CurmaxNum = 0; /* ��ǰ���Ů����ѡ��Ŀ */
		Person mostInvFemale;

		for (Person per : female)
		{
			vector<Person> maleList;

			auto it = hashmap.find(per);
			if (it != hashmap.end())
			{
				/* �õ�Ů�������Զ��� */
				maleList = it->second;
			}

			if (!maleList.empty())
			{
				/* ����Ů����ѡ��Ŀ��ͬ����� */
				if (maleList.size() == CurmaxNum)
				{
					mostInvFemale = choice(per, mostInvFemale);
				}
				else if (maleList.size() > CurmaxNum)
				{
					mostInvFemale = per;
					CurmaxNum = maleList.size();
				}
			}
		}
		return mostInvFemale;
	}

	/* �õ�������Ķ��� */
	Person satisfy(Person & choPer, vector<Person> & beChoPer)
	{
		Person suit;
		int maxValue = 0;

		/* ������ѡ���� */
		for (Person per : beChoPer)
		{
			/* ����ο�ֵ  */
			int val = choPer.getOlook() * per.getLook() +
				choPer.getOcharacter() * per.getCharacter() +
				choPer.getOtreasure() * per.getTreasure();

			if (val > maxValue)
			{
				suit = per;
				maxValue = val;
			}
			/* ���ֲο�ֵ��ͬ����� */
			else if (val == maxValue)
			{
				suit = choice(suit, per);
			}
		}
		return suit;
	}

	/* ������ͬ�ο�ֵ��ѡ��Ŀ��ͬ���ʱ�Ĵ��� */
	Person choice(Person & cur, Person & suit)
	{
		int presentNum = cur.getLook()
			+ cur.getCharacter() + cur.getTreasure();

		int bestNum = suit.getLook()
			+ suit.getCharacter() + suit.getTreasure();

		/* ����ο�ֵҲ����ͬ�Ƚ�id������id��-1������������ȼ���� */
		if (presentNum == bestNum)
			return cur.getId() < suit.getId() ? cur : suit;

		return presentNum > bestNum ? cur : suit;
	}
};

//=====================================================================================================
int main()
{
	Calculate cal(100);

	MyTimer timer;
	timer.Start();

	cal.start();

	timer.Stop();
	timer.showTime();

	//static omp_lock_t lock;
	//omp_init_lock(&lock);
	//#pragma omp parallel for
	//	for (size_t i = 0; i < 5000; i++)
	//	{
	//		omp_set_lock(&lock);
	//		cout << i << endl;
	//		omp_unset_lock(&lock);
	//	}
	//	omp_destroy_lock(&lock);
	//	timer.Stop();
	//	timer.showTime();
	return 0;
}
