#pragma once;
using namespace std;
class Item{
public:
	Item(); //default constructor

	//constructor with parameters
	Item(const char* nm, double pr, int qty,const char* category,int Id);
	~Item();
	//get and set methods
	void setName(const char* nm);
	void setID(int num);
	char* getName()const;
	void setPrice(double pr);
	double getPrice() const ;
	void setQuantity(int qty);
	int getQuantity() const;
	void setCategory(const char* ctg);
	char* getCategory() const;
	int getId() const;
	Item& operator=(const Item&);
	Item(const Item& rhs);
private:
	char* name;
	double price;
	int quantity;
	char* category;
	int id;
};
