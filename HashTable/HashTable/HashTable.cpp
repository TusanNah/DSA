#include "iostream"
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>
#define SIZE 2000
using namespace std;
struct Company
{
	string name;
	string tax_code;
	string address;
};

using namespace std;

vector<Company> ReadCompanyList(string file_name) {
	vector<Company> companyList;
	ifstream fin(file_name);
	if (!fin) {
		cout << endl << "Cant open file " << file_name << endl;
		companyList.~vector();
		return companyList;
	}
	cout << endl << "Open successfully " << file_name << endl;	
	string buffer;
	getline(fin, buffer, '\n');
	while (!fin.eof()) {
		Company info;
		getline(fin, info.name,'|');
		getline(fin, info.tax_code, '|');
		getline(fin, info.address, '\n');
		companyList.push_back(info);
	}
	return companyList;
}

// 2. Hash a string (company name) function:
;long long* p_pow_i_mod_m(int p, int size, long long m) {
	long long* p_power_i_mod_m = new long long[size];
	p_power_i_mod_m[0] =(long long)pow(p, 0) % m;
	for (int i = 1; i < size; i++) {
		p_power_i_mod_m[i] = (p_power_i_mod_m[i-1] * (p % m)) % m;
	}
	return p_power_i_mod_m;
}

long long HashString(string company_name) {
	string s;
	if (company_name.size() > 20) {
		s = company_name.substr(company_name.size() - 20, 20);
	}
	else
		s = company_name;
	long long sum = 0;
	int p = 31;
	long long m = pow(10, 9) + 9;
	long long* p_power_i_mod_m = p_pow_i_mod_m(p, s.size(), m);
	for (int i = 0; i < s.size(); i++) {
		int asciiCode = (int)s[i];
		sum += ((asciiCode % m) * p_power_i_mod_m[i]) % m;

	}
	return sum%m;
}
// 3. The function to create a hash table of size 2000, generated from the Companies list:
Company* CreateHashTable(vector<Company> list_company) {
	Company* hashTable = new Company[SIZE];
	for (int i = 0; i < SIZE; i++) {
		hashTable[i].name = hashTable[i].tax_code = hashTable[i].address = "";
	}
	for (int i=0; i < list_company.size(); i++) {
		int tempPos = HashString(list_company[i].name)%SIZE;
		/*cout << endl << "Hash string " << i << "...";*/
		int j = 0;
		int pos = tempPos + j;
		while (hashTable[pos].name != "" && hashTable[pos].address != "" && hashTable[pos].tax_code != "") {
			if (pos < SIZE - 1) {
				j++;
				pos = tempPos + j;
			}
			else { // pos==SIZE-1=1999
				pos = 0;
			}
		}
		hashTable[pos] = list_company[i];
		/*cout << endl << "lan thu " << i;*/
	}
	return hashTable;
}
void Insert(Company* hash_table, Company company) {
	int tempPos = HashString(company.name)%SIZE;
	int j = 0;
	int pos = tempPos + j;
	while (hash_table[pos].name != "" && hash_table[pos].address != "" && hash_table[pos].tax_code != "") {
		if (pos < SIZE - 1) {
			j++;
			pos = tempPos + j;
		}
		else { // pos==SIZE-1=1999
			pos = 0;
		}
	}
	hash_table[pos] = company;

}
// 5. Search for company information by its name
Company* Search(Company* hash_table, string company_name) {
	int tempPos = HashString(company_name)%SIZE;
	int j = 0;
	int pos = tempPos + j;
	while (hash_table[pos].name != company_name) {
		if (pos < SIZE - 1) {
			j++;
			pos = tempPos + j;
		}
		else { // pos==SIZE-1=1999
			pos = 0;
		}
		if (j >= SIZE)
			return NULL;
	}
	return &hash_table[pos];
}
void Write(string file_name, vector<Company> list) {
	ofstream fout(file_name);
	if (!fout) {
		cout << endl << "Cant open file " << file_name << endl;
		return;
	}
	cout << endl << "Open successfully " << file_name << endl;
	for (int i = 0; i < list.size(); i++) {
		fout << list[i].name << "|" << list[i].address << "|" << list[i].tax_code << endl;
	}
	return;
}
void print(Company c) {
	cout << endl << c.name << " " << c.tax_code << " " << c.address;
}
void main() {
	vector <Company> list = ReadCompanyList("data.txt");
	Write("output.txt", list);
	cout << list.size(); //1250
	
	Company* companyTable = CreateHashTable(list);
	cout << endl << "Create successfully !" << endl;
	cout << endl << "\t===HASH TABLE===" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << "Company " << i << ": " << companyTable[i].name << endl;
	}
	/*for (int i = 0; i < 1250; i++) {
		cout << endl << list[i].name  ;
	}*/
	Company company{ "CONG TY TRACH NHIEM MOT THANH VIEN", "21312512", "444/333 Huynh Van Banh" };
	Insert(companyTable, company);
	cout << endl << "Search successfully !" << endl;
	Company* searchCompany = Search(companyTable, company.name);
	cout << endl << searchCompany->name << "  " << searchCompany->address << " " << searchCompany->tax_code;
}
