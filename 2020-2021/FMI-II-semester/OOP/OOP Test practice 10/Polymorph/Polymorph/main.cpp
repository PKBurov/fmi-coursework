#include<iostream>
// Class Item e abstracten, zashtoto imame chisto virtualna funciq
// stiga da ima 1 e abstracten class, sledovatelno ne mojem da
// pravim obecti ot neq
class Item {
public:
	int price = 2;
	virtual void print() const = 0;
	

};
//Definirame virutalen destructor, koito se definira otvun;
//Ako imame char* gore, dolu trqbva da se trie vuv virtualniq
//Nasledqvame Base
class Pen : public Item {
public:
	int lenght = 15;
	//Item::print(); // Taka se zadava samo v virtual function
	virtual void print() const override {
		//Item::print(); // Izpulnqva purvo print of Item ako e = 0, gurmi
		std::cout << "Inside Derived\n";
	}
	int getLenght() const {
		return this->lenght;
	}
};

class Pencil : public Item {
	char hardness = 'B';
public:
	//Tuk tui kato nasledqva Item, imame Virtualna Print
	//koqto ne e divinirane i ako ne predevinirame stava abstracten
	//class ==>
	virtual void print() const  {
		std::cout << "Pencil hardness" << this->hardness << "\n";
	}
	char getHardnes() const {
		return this->hardness;
	}
};


int main() {
	
	//Item* pen = new Pen(); // Item sochi kum pen
	//Tuk ne mojem da izvikame Lenght na ptr;
//std::cout << ptr->lenght; //zashtoto imame pointar ot tip Item
	/*
	Kak da dostupim primerno metod koito ne e virtualen,
	i e ot tip Pen, ami 1 nachin e da vzemem pointara i da
	go castnem kum 
	*/
	//Moje i taka:
	//Pen* penPtr = (Pen*)pen;
	//((Pen*)pen)->getLenght();

    //std::cout << penPtr->getLenght();

	//Pak s polimorphysm
	Item* ptr = new Pen();
	Pen* pen = dynamic_cast<Pen*>(ptr);
	if (pen){ //Tuk moje da se pishe i if(pen) koeto e sushtoto
		std::cout << pen->getLenght();
	}else{
		std::cout << "Pointer is of different type\n";
		//Tuk mojem da probvame da go kastnem kum pencil;
		Pencil* pencil = dynamic_cast<Pencil*>(ptr);
		if (pencil){
			std::cout << pencil->getHardnes();
		}
	}


	//std::cout << pen->getLenght();


	delete ptr;
	//delete pencil;
}
/*Mnojestvo masivi ne sa otgovor kum magazin still primerno
	virtual-stava virtual na vsichki koito q nasledqva
	override- definirane e nqkude drugade, no tuk q promenqme
*/
// Polimorph, raboti s pointeri kum bazoviq klas, no sochi obekti ot
// nasledqvashtiq klass i kato vikenm print of base, da se pokaje ot derive