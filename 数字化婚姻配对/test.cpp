#include"stdafx.h"

const int MALE = 1;
const int FEMALE = 0;

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

vector<Person>getdata(string file, int gender)
{
	vector<Person>vec;
	vec.reserve(100);

	int id, look, character, treasure, olook, ocharacter, otreasure;
	FILE* fp;
	fopen_s(&fp, file.c_str(), "r");
	assert(fp != 0);

	for (int i = 0; i < 100; ++i)
	{
		fscanf_s(fp, "%d,%d,%d,%d,%d,%d,%d", 
			&id, &look, &character, &treasure, &olook, &ocharacter, &otreasure);

		Person per(gender,id, look, character, treasure, olook, ocharacter, otreasure);

		vec.push_back(per);
	}
	fclose(fp);
	return vec;

}
int main()
{
	vector<Person>vec(getdata("male.txt", MALE));
	for()


}