#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include "Question.h"

using namespace std;

int randomize(const int number)
{
	return rand() % number;
}

void printMenu()
{
	cout
		<< "Welcome to the SARS-Exam preparation program!\n"
		<< "Use digits 1-9 to mark answers.\n"
		<< "Press \"e\" to move to the next question.\n"
		<< "You can't go back to a previous question.\n"
		<< "You can mark and unmark answers on a question infinitely.\n"
		<< "The result for each question is calculated upon switching to the next one.\n"
		<< "Questions are randomized.\n\n"
		<< "Press \"q\" at any time to quit the program.\n"
		<< "Press any other key to start the test...\n";
}

int main()
{
	srand(time(NULL));
	char input = 0;
	int result = 0;
	int choice = 0;
	int maxResult = 0;
	vector<Question> exam;

	printMenu();
	input = _getch();
	if (input == 'q')
	{
		return 0;
	}


	/* Izpit 2018*/

	Question ex0("Koi ot slednite sa primer za dobre formuliran scenarii za kachestvo?\nIzberete edno ili poveche:");
	ex0
		.addOption("Dopustimo e sistemata da e v rezhim na poddryzhka za ne poveche ot 3 chasa sedmichno.", 1)
		.addOption("Potrebitelqt vliza v sistemata, izbira opciqta za tyrsene i vyvezhda opredelen simvolen niz.", 0)
		.addOption("Promeni v sistemata da se pravqt vyzmozhno nai-byrzo.", 0)
		.addOption("Otgovoryt na potrebitelskite zaqvki trqbva da stane do 3 sekundi.", 1);
	exam.emplace_back(ex0);

	Question ex1("Smisylyt na nefunkcionalnite iziskvaniq v sistemata e:\n(Izberete edno)");
	ex1
		.addOption("Da se ulesni razrabotkata na sistemata.", 0)
		.addOption("Da se izpolzvat nai-syvremennite tehnologii i programni ezici.", 0)
		.addOption("Da se namali cenata na razrabotka na softuernata sistema.", 0)
		.addOption("Da se utochni po kakyv nachin i pri kakvi usloviq shte raboti sistemata.", 1);
	exam.emplace_back(ex1);

	Question ex2("V 4+1 modela na softuernata arhitektura izgledyt na procesite pokazva kak sistemata se dekompozira na systavni softuerni elementi (moduli).\nIzberete edno:");
	ex2
		.addOption("Istina.", 0)
		.addOption("Lyzha.", 1);
	exam.emplace_back(ex2);

	Question ex3("Pod proizvoditelnost (performance) v softuernite sistemi se razbira:\nIzberete edno:");
	ex3
		.addOption("Vyzmozhnost na sistemata da osiguri rabota bez otkaz.", 0)
		.addOption("Vremeto, za koeto sistemata reagira na vyznikvashite sybitiq.", 1)
		.addOption("Mqrka za sebestoinostta na promenite v sistemata.", 0)
		.addOption("Vyzmozhnost na potrebitelq byrzo da ovladee sistemata.", 0);
	exam.emplace_back(ex3);

	Question ex4("V koi ot slednite redove e dopusnata greshka?\nIzberete edno:");
	ex4
		.addOption("Vyzdeistvie, algoritym i iztochnik sa elementi na scenariite za kachestvo.", 1)
		.addOption("Vyzdeistvie, kolichestveni parametri i kontekst sa elementi na scenariite za kachestvo.", 0)
		.addOption("Vyzdeistvie, rezultat i iztochnik sa elementi na scenariite za kachestvo.", 0)
		.addOption("Vyzdeistvie, obekt i iztochnik sa elementi na scenariite za kachestvo.", 0);
	exam.emplace_back(ex4);

	Question ex5("Proektiraneto na softuernata arhitektura e iterativen proces.\nIzberete edno:");
	ex5
		.addOption("Istina.", 1)
		.addOption("Lyzha.", 0);
	exam.emplace_back(ex5);

	Question ex6("Cost Benefit Analysis Method (CBAM) e proces, pri koito:\nIzberete edno:");
	ex6
		.addOption("se opredelqt nai-vazhnite iziskvaniq kym dokumentaciqta na arhitekturata.", 0)
		.addOption("Nito edno ot izbroenite ne e vqrno.", 1)
		.addOption("se ocenqva proizvoditelnostta na sistemata.", 0)
		.addOption("se proverqva dali proektiranata veche arhitektura udovletvorqva postavenite iziskvaniq.", 0);
	exam.emplace_back(ex6);

	Question ex7("Pri kakyv tip sistemi e nai-podhodqshto da se izpolzva struktura na vnedrqvaneto (deployment)?\nIzberete edno:");
	ex7
		.addOption("Koito se izpylnqvat na edna mashina", 0)
		.addOption("Sistemi s mnogo potrebiteli", 0)
		.addOption("Nito edin ot posochenite", 1)
		.addOption("Koito se izpylnqvat v cloud", 0);
	exam.emplace_back(ex7);

	Question ex8("Arhitekturniqt stil (shablon) predstavlqva:\nIzberete edno:");
	ex8
		.addOption("obektno-orientiran model na softuernata sistema.", 0)
		.addOption("opisanie na softuernata arhitektura.", 0)
		.addOption("tipovo arhitekturno reshenie, koeto se e dokazalo pri upotreba v konkretni situacii.", 1)
		.addOption("model za prehod ot softuerna arhitektura kym kod.", 0);
	exam.emplace_back(ex8);

	Question ex9("Pri proektiraneto na arhitekturata mozhe da se ogranichi broqt na modulite, s koito daden komponent komunikira, za da se:\nIzberete edno:");
	ex9
		.addOption("ogranichi neobhodimostta ot promeni v drugi moduli, s koito dadeniqt komunikira.", 1)
		.addOption("namali slozhnostta na sistemata i da se uskori procesa na razrabotka.", 0)
		.addOption("napravi arhitekturata po-qsna i da se razbira ot vsichki zainteresovani lica.", 0)
		.addOption("Ne se prilaga takava taktika.", 0);

	Question ex10("Strukturata na procesite:\nIzberete edno:");
	ex10
		.addOption("Posochva zadylzheniqta na otdelnite zainteresovani lica.", 0)
		.addOption("Pokazva posledovatelnostta na izpylnenie na otdelnite komponenti v sistemata.", 1)
		.addOption("E izgotven ot menidzyra na proekta dokument, koito naznachava zadachite na ostanalite uchastnici v razrabotkata na proekta.", 0)
		.addOption("Pokazva abstraktni grupi ot hora, koito realizirat modulite na sistemata.", 0);
	exam.emplace_back(ex10);

	Question ex11("Koe ot slednite ne e vqrno za arhitekturniq stil Pipe-Filter?\nIzberete edno:");
	ex11
		.addOption("Ima trudnosti pri realizaciqta na interaktivni prilozheniq.", 0)
		.addOption("Vodi do prosti za proektirane i realizaciq arhitekturi.", 0)
		.addOption("Nqma vyzmozhnost za paralelna obrabotka na informaciqta.", 1)
		.addOption("Strukturata mu e identichna sys strukturata na povecheto standartni biznes procesi v organizaciite.", 0);
	exam.emplace_back(ex11);

	Question ex12("V softuernata arhitektura e redno da se opisvat svoistva i metodi na klasovete, koito izgrazhdat obektite v sistemata.\nIzberete edno:");
	ex12
		.addOption("Istina.", 0)
		.addOption("Lyzha.", 1);
	exam.emplace_back(ex12);

	Question ex13("*V koi ot slednite deinosti e redno da vzimat uchastie softuernite arhitekti?\nIzberete edno ili poveche:");
	ex13
		.addOption("Opredelqne na algoritmite za razrabotka na sistemata", 0)
		.addOption("Razrabotka na sistemata.", 0)
		.addOption("Utochnqvane iziskvaniqta kym softuernata sistema",1)
		.addOption("Proektirane na arhitekturata", 1)
		.addOption("Izgotvqne na biznes plan na proekta", 1);
	exam.emplace_back(ex13);

	Question ex15("Dokumentaciqta na softuernata arhitektura:\nIzberete edno ili poveche:");
	ex15
		.addOption("Vkliuchva kolkoto e vyzmozhno poveche strukturi", 0)
		.addOption("Vkliuchva kolkoto e vyzmozhno po-malko strukturi", 0)
		.addOption("Vkliuchva opredeleni strukturi, v zavisimost ot samata sistema i tova koi shte chete dokumentaciqta", 1)
		.addOption("Vkliuchva opisanie na strukturite na arhitekturata plus pridruzhavashti dokumenti", 1);
	exam.emplace_back(ex15);

	Question ex16("Spored definiciqta softuernata arhitektura predstavlqva nabor ot strukturi. V tazi vryzka mozhe li da se kazhe, che dekompoziciqta na moduli e arhitektura na sistemata?\nIzberete edno:");
	ex16
		.addOption("Istina", 0)
		.addOption("Lyzha", 1);
	exam.emplace_back(ex16);

	Question ex17("Mozhe li da se tvyrdi sys sigurnost, che izpolzvaneto na replikaciq na sistemata ili chasti ot neq, s cel osigurqvane na nadezhnost, vliqe otricatelno na sigurnostta?\nIzberete edno:");
	ex17
		.addOption("Da", 0)
		.addOption("Ne", 0)
		.addOption("Vyzmozhno ne, no zavisi ot konkretnite scenarii za kachestvo", 1);
	exam.emplace_back(ex17);

	Question ex18("V arhitekturniq stil Shared Data:\nIzberete edno:");
	ex18
		.addOption("Nito edin ot posochenite otgovori ne e veren", 0)
		.addOption("Lesno se realizira paralelno izpylnenie na procesite, koito obrabotvat dannite", 0)
		.addOption("Vsichki uchastvashti komponenti imat vyzmozhnost za dostyp do spodeleni danni", 1)
		.addOption("Dannite se izprashtat ednovremenno do vsichki uchastvashti komponenti", 0);
	exam.emplace_back(ex18);

	Question ex19("Koe ot slednite tvyrdeniq e nevqrno?\nIzberete edno:");
	ex19
		.addOption("Pri mnogosloiniq arhitekturen stil interfeisite opredelqt protokol za vzaimodeistvie mezhdu nivata.", 0)
		.addOption("Za da se prilozhi mnogosloiniqt arhitekturen stil se iziskva specializiran hardware.", 1)
		.addOption("Mrezhoviqt model na OSI e proektiran spored principite na mnogosloiniq arhitekturen stil.", 0)
		.addOption("Pri mnogosloiniq arhitekturen stil vsqko nivo predostavq interface na nivo nad nego i izpolzva interfeisite ot nivoto tochno pod nego.", 0);
	exam.emplace_back(ex19);

	Question ex20("V stila client-server komponentite vzaimodeistvat pomezhdu si chrez izprashtane na syobshtenie (ili izvikvane na metod), pri koeto izprashtastiqt komponent ne znae nishto za poluchatelq.\nIzberete edno:");
	ex20
		.addOption("Istina.", 1)
		.addOption("Lyzha.", 0);
	exam.emplace_back(ex20);

	Question ex21("Softuernata arhitektura NE E:\nIzberete edno:");
	ex21
		.addOption("Abstraktno opisanie na sistemata ot razlichni gledni tochki, koeto zasqga minimalen broi ot zainteresovanite lica.", 1)
		.addOption("Dokument, v koito lipsvat podrobnosti za koda na sistemata", 0)
		.addOption("Model na upravlenieto na procesite v sistemata", 0)
		.addOption("Syvkupnost ot predstavqne na sistemata ot razlichni gledni tochki", 0);
	exam.emplace_back(ex21);

	Question ex22("Sigurnost i otkazoustoichivost (fault-tolerance) sa dve nefunkcionalni harakteristiki, koito chesto si protivorechat.\nIzberete edno:");
	ex22
		.addOption("Istina.", 1)
		.addOption("Lyzha.", 0);
	exam.emplace_back(ex22);

	Question ex23("Spored vas, primer za dobre napravena dekompoziciq na modulite li e pokazanata diagrama?(3 kashoncheta)\n[Computation [Math] [Data Repository] ]\n[Communication [Protocols] [Data Repository] ]\n[Processing [User Interface] [Data Repository] ]\nIzberete edno:");
	ex23
		.addOption("Istina.", 0)
		.addOption("Lyzha.", 1);
	exam.emplace_back(ex23);

	Question ex24("Koe ot slednite tvyrdeniq ne e vqrno po otnoshenie na NeFunkcionalnite iziskvaniq (NFI)?\nIzberete edno:");
	ex24
		.addOption("NFI sa chesto protivorechivi i se nalaga da se pravqt kompromisi mezhdu tqh.", 0)
		.addOption("NFI si vliqqt s iziskvaniqta po funkcionalnostta na sistemata.", 0)
		.addOption("NFI trqbva da se balansirat sprqmo interesite na zainteresovanite lica.", 0)
		.addOption("NFI ne sa opredelqshti za dekompoziciqta na sistemata na moduli.", 1);
	exam.emplace_back(ex24);

	Question ex25("Koi ot slednite mozhe da harakterizirat nadezhnost na sistemata?\nIzberete edno ili poveche:");
	ex25
		.addOption("Procent uspeshni izvikvaniq", 1)
		.addOption("Veroqtnost za otkaz", 1)
		.addOption("Latentnost", 0)
		.addOption("Vreme za izpylnenie", 0);
	exam.emplace_back(ex25);

	Question ex26("Broqt na strukturite, koito shte bydat vkliucheni v dokumentaciqta na softuernata arhitektura, zavisi ot:\nIzberete edno ili poveche:");
	ex26
		.addOption("Vidyt na zainteresovanite lica", 1)
		.addOption("Softuernata sistema", 1)
		.addOption("Prilozhnata oblast, kydeto shte se vnedrqva softuernata sistema", 0)
		.addOption("Kodyt na sistemata", 0);
	exam.emplace_back(ex26);

	Question ex27("Kakvo predstavlqvat arhitekturnite draiveri ot gledna tochka na procesa na proektirane?\nIzberete edno:");
	ex27
		.addOption("Vryzka mezhdu arhitekturata na sistemata i neinata realizaciq.", 0)
		.addOption("Sredstvo za ulesnqvane na proektirane na softuernata arhitektura.", 0)
		.addOption("Iziskvaniqta kym sistemata, koito imat nai-visok prioritet.", 1)
		.addOption("Nai-vazhnite tehnologii, koito shte bydat izpolzvani.", 0);
	exam.emplace_back(ex27);

	Question ex28("Koe ot slednite tvyrdeniq e vqrno za stila kanal-filter (pipe and filter)?\nIzberete edno:");
	ex28
		.addOption("V tozi arhitekturen stil nqma syedinitelni moduli.", 0)
		.addOption("Tozi stil ne se preporychva pri razrabotka na sistemi, koito obrabotvat razlichni po format danni.", 1)
		.addOption("Komponentite v stila kanal-filter se realizirat samo na ezika Java.", 0)
		.addOption("Vseki modul (komponent) v sistemata predava dannite v proizvolen red na sledvashtiq komponent.", 0);
	exam.emplace_back(ex28);

	Question ex29("V stilyt neqvno izvikvane (implicit invocation) komponentite vzaimodeistvat pomezhdu si chrez:\nIzberete edno:");
	ex29
		.addOption("Izprashtane na t.nar. sybitiq, pri koito izprashtashtiqt komponent ne znae nishto za poluchatelq.", 1)
		.addOption("Izvikvane na metod, pri koeto izprashtashtiqt komponent izchakva za otgovor, predi da prodylzhi sys svoeto izpylnenie.", 0)
		.addOption("Izprashtane na t.nar. sybitiq, pri koito izprashtashtiqt komponent ima informaciq za poluchatelq.", 0);
	exam.emplace_back(ex29);

	Question ex30("Koe ot izbroenite ne vliqe vyrhu izbora na arhitekturni taktiki?\nIzberete edno:");
	ex30
		.addOption("Bydeshti planove za razvitie na organizaciqta", 0)
		.addOption("Broqt na kvalifikaciqta na nalichnite razrabotchici", 0)
		.addOption("Kvalifikaciqta na menidzyra na proekta", 1)
		.addOption("Nalichie na nasleden (legacy) software", 0);
	exam.emplace_back(ex30);

	Question ex31("Shablonyt fasada (facade), kakto e pokazan na figurata, se izpolzva pri neobhodimost ot uvelichavane na byrzodeistvieto na programata.\n________      ________________\n|Facade|      |Subsystem      |\n________      _______________\n|      | -----|------->[     ]|\n________      ________________\n|      | -----|-->[     ]     |\n________      ________________\n\nIzberete edno:");
	ex31
		.addOption("Istina.", 0)
		.addOption("Lyzha.", 1);
	exam.emplace_back(ex31);

	Question ex32("Arhitekturniqt stil Circuit Breaker:\nIzberete edno:");
	ex32
		.addOption("Znachitelno podobrqva izmenqemostta na sistemata.", 0)
		.addOption("Podobrqva samo nadezhdnostta na sistemata.", 1)
		.addOption("Podobrqva nadezhdnostta i proizvoditelnostta na sistemata.", 0)
		.addOption("Namalqva znachitelno izmenqemostta na sistemata.", 0);
	exam.emplace_back(ex32);

	Question ex14("Koe ot slednite ne e primer za arhitekturen pohvat za postigane na nadezhdnost v softuernite sistemi?\nIzberete edno:");
	ex14
		.addOption("Shared bus", 1)
		.addOption("Izlishyk (redundancy)", 0)
		.addOption("N-version programming", 0)
		.addOption("Heartbeat (Keep-alive)", 0);
	exam.emplace_back(ex14);


	/* Testove -> Variant B 07.07.2011 g. */

	Question q0("Softuernata arhitektura NE e:");
	q0
		.addOption("Abstrakciq, koqto skriva detailite po realizaciqta na programite", -1)
		.addOption("Dokument, koito mozhe da podobri organizatsiqta na rabota v softuernata kompaniq", -1)
		.addOption("Model na strukturata za upravlenie na softuernata kompaniq", 1)
		.addOption("Syvkupnost ot predstavqne na sistemata ot razlichni gledni tochki", -1);
	exam.emplace_back(q0);

	Question q1("Spored teoriqta v strukturata na konkurentnoto izpylnenie sa komponenti i nishki (logical threads) sinhronizacionnite i komunikacionni vryzki mezhdu tqh. Za kakvo mozhe da se izpolzva tazi struktura?");
	q1
		.addOption("Za opredelqne na harduernite iziskvaniq na sistemata", -1)
		.addOption("Za razpredelqne na rabotata po implementaciqta na sistemata mezhdu razlichnite ekipi", -1)
		.addOption("Za otsenqvane na nefunkcionalnite harakteristiki na sistemata", -1)
		.addOption("Za analiz na vzaimodeistvieto mezhdu procesite i predotvratqvane na blokirovki (deadlocks)", 1);
	exam.emplace_back(q1);

	Question q2("Koi ot slednite mozhe da harakterizirat proizvoditelnost na sistemata?\n(2 verni otgovora)");
	q2
		.addOption("Vreme za izpylnenie", 1)
		.addOption("Veroqtnost za otkaz", -1)
		.addOption("Sredno vreme za vyzstanovqvane", -1)
		.addOption("Latentnost", 1);
	exam.emplace_back(q2);

	Question q3("Softuerniqt arhitekt raboti nezavisimo ot ostanalite zainteresovani lica.");
	q3
		.addOption("vqrno", -1)
		.addOption("nevqrno", 1);
	exam.emplace_back(q3);

	Question q4("Izboryt na strukturi, koito shte bydat vkliucheni v dokumentaciqta na softuernata arhitektura zavisi ot:\n(2 verni otgovora)");
	q4
		.addOption("Prilozhnata oblast, kydeto shte se vnedrqva softuernata sistema", -1)
		.addOption("Nefunkcionalnite iziskvaniq (kachestvenite harakteristiki)", 1)
		.addOption("Broqt na zainteresovanite litsa", -1)
		.addOption("Konkretnite zainteresovani litsa, koito shte chetat dokumentaciqta", 1);
	exam.emplace_back(q4);

	Question q5("Koi ot slednite tvyrdeniq ne sa verni po otnoshenie na nefunkcionalnite iziskvaniq (NFI)?");
	q5
		.addOption("NFI sa chesto protivorechivi i se nalaga da se pravqt kompromisi mezhdu tqh", -1)
		.addOption("NFI sa opredelqshti za dekompozitsiqta na sistemata na moduli", -1)
		.addOption("NFI ne si vliqqt s iziskvaniqta po funkcionalnostta na sistemata", 1)
		.addOption("Nadezhdnostta na sistemata e nefunkcionalno iziskvane", -1);
	exam.emplace_back(q5);

	Question q6("Pod izpitaemost (testability) w softuernata sistema se razbira:");
	q6
		.addOption("Vremeto, za koeto sistemata reagira na vyznikvashtite sybitiq", -1)
		.addOption("Vyzmozhnost na sistemata da osiguri rabota bez otkaz", -1)
		.addOption("Lekota pri otkrivane na greshki v softuera", 1)
		.addOption("Mqrka za sebestoinostta na promenite v sistemata", -1);
	exam.emplace_back(q6);

	Question q7("Arhitekturniqt rechnik i obosnovkata na arhitekturnite resheniq sa nerazdelna chast ot dokumentatsiqta na softuernata arhitektura.");
	q7
		.addOption("da", 1)
		.addOption("ne", -1);
	exam.emplace_back(q7);

	Question q8("Koi ot slednite sa primer za dobre formulirani scenarii za kachestvo?\n(2 verni otgovora)");
	q8
		.addOption("Pri otvarqne na file, antivirusnata programa trqbva da go proveri vyzmozhno nai-byrzo.", -1)
		.addOption("Sistemata za avtomatichna blokirovka trqbva da prekysne zahranvaneto kym manipulatora nai-mnogo za 20ms sled registriraneto na temperatura po-golqma ot 50 gradusa.", 1)
		.addOption("Avtomatichnata vrata trqbva da spre dvizhenieto si ne po-kysno ot 0.3 sekundi sled otkrivane na prepqtstvie.", 1)
		.addOption("Sistemata trqbva da e sigurna", -1);
	exam.emplace_back(q8);

	Question q9("Pod sigurnost (security) v softuernite sistemi se razbira:");
	q9
		.addOption("Vyzmozhnost na sistemata da osiguri rabota bez otkaz", -1)
		.addOption("Mqrka za sposobnostta na sistemata da ustoqva na opiti za nerazreshena upotreba bez tova da prechi na registriranite potrebiteli", 1)
		.addOption("Mqrka za sebestoinostta na promenite v sistemata", -1)
		.addOption("Uverenost v uspeshnoto izpylnenie na proekta", -1);
	exam.emplace_back(q9);

	Question q10("Izlishykyt (redundancy) kato taktika za postigane na izmenqemost predstavlqva:");
	q10
		.addOption("Osigurqvane na dopylnitelni resursi s cel uspeshen zavyrshek na proekta.", -1)
		.addOption("Osigurqvane na dopylnitelni kopiq na otdelni moduli na sistemata.", -1)
		.addOption("Nqma takava taktika za postigane na izmenqemost.", 1);
	exam.emplace_back(q10);

	Question q11("Pod proizvoditelnost (performance) v softuernite sistemi se razbira:");
	q11
		.addOption("Vremeto, za koeto sistemata reagira na vyznikvashtite sybitiq.", 1)
		.addOption("Vyzmozhnost na potrebitelq da vyrshi byrzo svoqta rabota.", -1)
		.addOption("Vyzmozhnost na sistemata da osiguri rabota bez otkaz.", -1)
		.addOption("Mqrka za sebestoinostta na promenite v sistemata.", -1);
	exam.emplace_back(q11);

	Question q12("Kontrolnite tochki (checkpoint) kato taktika za postigane na gotovnost (availability) predstavlqvat celenasocheno izprashtane na signal mezhdu dva modula s cel ediniqt da se uveri, che drugiqt e aktiven.");
	q12
		.addOption("vqrno", -1)
		.addOption("nevqrno", 1);
	exam.emplace_back(q12);

	Question q13("Chrez izpolzvaneto na obvivki (posrednik/mediator/wrapper) pri proektirane na softuerna arhitektura ne se podobrqva izmenqemostta na sistemata, no ima vyzmozhnost za povishavane na sigurnostta.");
	q13
		.addOption("vqrno", -1)
		.addOption("nevqrno", 1);
	exam.emplace_back(q13);

	Question q14("Osnovnoto predimstvo pri t.nar. otlagane na svyrzvaneto (finalnata integratsiq na sistemata se pravi pri potrebitelq) e:");
	q14
		.addOption("povishava se izmenqemostta na sistemata.", 1)
		.addOption("povishava se sigurnostta na sistemata.", -1)
		.addOption("ulesnqva se rabotata na krainite potrebiteli.", -1)
		.addOption("namalqva se tsenata na razrabotka.", -1);
	exam.emplace_back(q14);

	Question q15("Kakvo predstavlqvat arhitekturnite driveri ot gledna tochka na procesa na proektirane?");
	q15
		.addOption("Nai-vazhnite tehnologii, koito shte bydat izpolzvani.", -1)
		.addOption("Vryzka mezhdu arhitekturata na sistemata i neinata realizaciq.", -1)
		.addOption("Sredstvo za ulesnqvane na proektiraneto na softuernata arhitektura.", -1)
		.addOption("Iziskvaniqta kum sistemata,koito imat nai-visok prioritet.", 1);
	exam.emplace_back(q15);

	Question q16("Koi ot slednite metodi mozhe da se prilozhat za povishavane na proizvoditelnostta na sistemata?\n(4 verni otgovora)");
	q16
		.addOption("Podobrqvane na algoritmite", 1)
		.addOption("Vyvezhdane na obvivni moduli", -1)
		.addOption("Promqna na perioda (pri sinhronni sistemi)", 1)
		.addOption("Vyvezhdane na opashka s kraen razmer", 1)
		.addOption("Uvelichavane na broq na modulite v sistemata", -1)
		.addOption("Vkliuchvane na dopylnitelni resursi", 1);
	exam.emplace_back(q16);

	Question q17("Nai-podhodqshtiqt podhod za proektirane na softuerna arhitektura e da se zapochne ot iziskvaniqta kym kachestvoto na sistemata (nefunkcionalnite iziskvaniq).");
	q17
		.addOption("vqrno", 1)
		.addOption("nevqrno", -1);
	exam.emplace_back(q17);

	Question q18("S kakvo zapochva realizatsiqta na softuernata sistema?\n(2 verni otgovora)");
	q18
		.addOption("Osnovnite komponenti, koito realizirat protokolite na vzaimodeistvie (middleware).", 1)
		.addOption("Sys specifichnite nai-chesto izpolzvani metodi za obrabotka na informaciqta.", 1)
		.addOption("Realizirat se pyrvo interfeisite na komponentite.", -1);
	exam.emplace_back(q18);

	Question q19("Spored definitsiqta softuernata arhitektura predstavlqva nabor ot strukturi. V tazi vryzka mozhe li da se kazhe, che dekompoziciqta na moduli e arhitektura na sistemata?");
	q19
		.addOption("Da.", -1)
		.addOption("Ne.", 1);
	exam.emplace_back(q19);

	Question q20("Analizyt na softuerni arhitekturi e proces, pri koito:");
	q20
		.addOption("se proverqva dali proektiranata veche arhitektura udovletvorqva postavenite iziskvaniq.", 1)
		.addOption("se ocenqva proizvoditelnostta na sistemata.", -1)
		.addOption("se opredelqt nai-vazhnite iziskvaniq kym arhitekturata.", -1);
	exam.emplace_back(q20);

	Question q21("Analizyt na softuerni arhitekturi vkliuchva razlichni fazi, sreshti i razgovori mezhdu zainteresovanite lica i ocenqvasht ekip.");
	q21
		.addOption("Vqrno.", 1)
		.addOption("Nevqrno", -1);
	exam.emplace_back(q21);

	Question q22("Koe ot slednite ne e vqrno:");
	q22
		.addOption("V ATAM vzimat uchastie vsichki zainteresovani lica.", -1)
		.addOption("ATAM ocenqva dokolko kodyt na sistemata otgovarq na arhitekturata.", 1)
		.addOption("Razkriva do kakva stepen arhitekturata udovletvorqva kachestvenite iziskvaniq.", -1)
		.addOption("Ne dava ocenka na biznes polzata ot sistemata.", -1);
	exam.emplace_back(q22);

	Question q23("Proektiraneto na softuernata arhitektura zapochva sled analiza na softuernite iziskvaniq.");
	q23
		.addOption("Vqrno.", 1)
		.addOption("Nevqrno.", -1);
	exam.emplace_back(q23);

	Question q24("Pri proektiraneto na arhitekturata mozhe da se ogranichi broqt na modulite, s koito daden komponent komunikira, za da se:");
	q24
		.addOption("namali slozhnostta na sistemata i da se uskori procesa na razrabotka.", -1)
		.addOption("napravi arhitekturata po-qsna i da se razbira ot vsichki zainteresovani lica.", -1)
		.addOption("ogranichi neobhodimostta ot promeni v drugi moduli, s koito dadeniqt komunikira.", 1)
		.addOption("Ne se prilaga takava taktika.", -1);
	exam.emplace_back(q24);

	Question q25("V koi ot slednite redove e dopusnata greshka?");
	q25
		.addOption("Vyzdeistvie, obekt i iztochnik sa elementi na scenariite za kachestvo.", -1)
		.addOption("Vyzdeistvie, rezultat i iztochnik sa elementi na scenariite za kachestvo.", -1)
		.addOption("Vyzdeistvie, algoritym i iztochnik sa elementi na scenariite za kachestvo.", 1)
		.addOption("Vyzdeistvie, kolichestveni parametri i kontekst sa elementi na scenariite za kachestvo.", -1);
	exam.emplace_back(q25);

	Question t0("Pokazanata figura moje da se razglejda kato: (snimka na vyrha Experiment control)");
	t0
		.addOption("Model na softuernata arhitektura", 0)
		.addOption("Use-case diagrama", 0)
		.addOption("Struktura - dekompoziciq na modulite", 0)
		.addOption("Struktura - upotreba na modulite (uses structure)", 1);
	exam.emplace_back(t0);

    Question t1("Arhitekturniq stil(shablon) predstavlqva");
	t1
		.addOption("Definiciq na opredeleni tipove arhitekturni elementi, zaedno sys nachina na tqhnoto svyrzvane", 1)
		.addOption("Standart za dokumentaciq na softuernata arhitektura", 0)
		.addOption("Model za prehod ot softuerna arhitektura kum kod", 0);
	exam.emplace_back(t1);

    Question t2("Pri kakuv tip sistema e nai-podhodqshto da se izpolzva struktura na vnedrqvaneto(deployment)");
	t2
		.addOption("Centralizirani", 0)
		.addOption("Razpredeleni", 1)
		.addOption("Sistemi s paralelno-protichashti procesi", 0);
	exam.emplace_back(t2);

	Question t3("Redno li e v softuernata arhitektura da se opisvat svoistva i metodi na klasovete, koito izgrajdat obektite v sistemata");
	t3
		.addOption("Da", 0)
		.addOption("Ne", 1);
	exam.emplace_back(t3);

	Question t4("Koi ot izbroenite vliqqt vyrhu izbora na softuerna arhitektura(3 verni)");
	t4
		.addOption("Predishen opit v organizaciqta ", 1)
		.addOption("Syvremenni tehnologichni tendencii", 1)
		.addOption("Broqt proekti na QA specialistite v organizaciqta", 0)
		.addOption("Opit i rutina na softuernite arhitekti", 1);
	exam.emplace_back(t4);

	Question t5("V koi ot slednite deinosti e redno da vzimat uchastie softuernite arhitekti(3 verni)");
	t5
		.addOption("Razrabotkata na sistemata", 0)
		.addOption("Analiz i ocenka na SA", 1)
		.addOption("Dokumentirane na doftuernata arhitektura", 1)
		.addOption("Razpredelqne na biudjeta na proekta za razrbotka na sistemata", 0)
		.addOption("Razbirane na iziskvaniqta", 1);
	exam.emplace_back(t5);

	Question t6("Strukturata na razpredelenie na rabotata(work assignment)");
	t6
		.addOption("Pokazva abstraktni grupi ot hora, koito realizirat modulite na sistemata", 1)
		.addOption("E izgotven ot menidjura na proekta dokument, koito naznachava zadachite na ostanalite uchastnici v razrabotkata na proekta", 0)
		.addOption("Posochva zaduljeniqta na ostanalite zainteresovani lica", 0)
		.addOption("Pokazva posledovatelnostta na izpulnenie na otdelnite komponenti v sistemata", 0);
	exam.emplace_back(t6);

	Question t7("Smisulut na nefunkcionalnite iziskvaniq kum sistemata e");
	t7
		.addOption("Da se zipolzvat nai-syvremennite tehnologii i programni ezici", 0)
		.addOption("Da se namali cenata na razrabotka na softuernata sistema", 0)
		.addOption("Da se postavqt dopulnitelni usloviq, koito opredelqt kak sistemata shte reazlizira funkcionalnostta si", 1)
		.addOption("Da se ulesnni razrabotkata na sistemata", 0);
	exam.emplace_back(t7);

	Question t8("Scenariqt za kachestvo predstavlqva specifichno iziskvane kum povedenieto na dadena sistema v zavisimost ot opredeleno kachestvo");
	t8
		.addOption("Da", 1)
		.addOption("Ne", 0);
	exam.emplace_back(t8);

    Question t9("Pod gotovnost(availability) v softuernite sistemi se razbira:\nIzberete edno:");
	t9
		.addOption("Vyzmozhnost na sistemata da osiguri rabota bez otkaz", 1)
		.addOption("Vremeto, za koeto sistemata reagira na vyznikvashite sybitiq", 0)
		.addOption("Mqrka za sebestoinostta na promenite v sistemata", 0)
		.addOption("Lekota pri otkrivane na greshki v softuera", 0);
	exam.emplace_back(t9);

	Question t10("Koe ot slednite ne e e primer za arhitekturna taktika za postigane na gotovnost v softuernite sistemi");
	t10
		.addOption("Dekompoziciq na moduli", 1)
		.addOption("Eho (ping/echo)", 0)
		.addOption("Heartbeat(keepalive)", 0)
		.addOption("Izlishuk(redundancy)", 0);
	exam.emplace_back(t10);

    Question t11("Smisulut na taktikite za lokalizirane na promenite(za postigane na izmenqemost) e:");
	t11
		.addOption("Da se predvidqt vuzmojnite mesta za budeshti promeni v sistemata i da se obosobqt v ramkite na minimalen broi moduli", 1)
		.addOption("Da ne se promenq arhitekturata po vreme na razrabotka na sistemata", 0)
		.addOption("Periodichno sybirane na ekipite po razrabotka na sistemata na edno mqsto", 0)
		.addOption("Nqma takava taktika za postigane na izmenqemost", 0);
	exam.emplace_back(t11);

    Question t12("Moje li restartiraneto na daden modul/komponent ot sistemata da se schita za taktika za postigane na gotvonost");
	t12
		.addOption("Da", 1)
		.addOption("Ne", 0);
	exam.emplace_back(t12);

	Question t13("Procesyt po proektirane na arhitektyrata e vuzmojno da produlji dori i sled syzdavane na skeletnata sistema");
	t13
		.addOption("Vqrno", 1)
		.addOption("Nevqrno", 0);
	exam.emplace_back(t13);

	Question t14("Koe ot slednite NE e vqrno po otnoshenie na dokumentaciqta na softuernata arhitektura");
	t14
		.addOption("Procesyt na dokumentirane vkluchva izvestna doza tvorchestvo", 0)
		.addOption("doumentaciqta na arhitekturata se opredelq ot tova koi shte q izpolzva", 0)
		.addOption("Osnoven princip pri suzdavaneto e da se napishe vuzmojno nai-byrzo", 1)
		.addOption("Vkluchva nabor ot dokumenti", 0);
	exam.emplace_back(t14);

	Question t15("Primer za kakvo e slednata diagrama (A -B,C,D)");
	t15
		.addOption("Pravilno proektirana ierarhichna sistema", 0)
		.addOption("UML-diagrama na zavisimostite mejdu modulite", 0)
		.addOption("UML-diagrama na dekompoziciq na modulite", 1)
		.addOption("Razpredelena sistema", 0);
	exam.emplace_back(t15);

	Question t16("V analiza na softuernata arhitektyra moje da se vkluchat i razlichni metodi za ocenqvane na biznes-polzata ot taka proektiranata sistema");
	t16
		.addOption("Da", 1)
		.addOption("Ne", 0);
	exam.emplace_back(t16);

	Question t17("V ramkite na procesa na ocenqvane, arhitekta pravi prezentacii na arhitekturata");
	t17
		.addOption("Vqrno", 1)
		.addOption("Nevqrno", 0);
	exam.emplace_back(t17);
	unsigned int i = 0;

	/* Randomize Questions */
	unsigned int questionsCount = exam.size();
	for (i = 0; i < questionsCount; ++i)
	{
		swap(exam[randomize(questionsCount)], exam[randomize(questionsCount)]);
	}

	for (i = 0; i < questionsCount; ++i)
	{
		maxResult += exam[i].getMaxResult();
	}

	/* Display Questions */
	for (i = 0; i < questionsCount; ++i)
	{
		if (input == 'q')
		{
			break;
		}
		input = '0';

		/* Current Question */
		choice = 0;
		while (input != 'e' && input != 'q')
		{
			system("cls");
			cout << "Question " << i + 1 << "/" << questionsCount << " Press \"e\" to move to the next question. Press \"q\" to end the test.\n\n";
			exam[i].print();
			input = _getch();
			choice = input - '0';
			if (isdigit(input) && choice > 0 && choice <= exam[i].getOptionCount())
			{
				exam[i].choose(choice - 1);
			}
		}
        exam[i].printAllCorrect();
        system("pause");
		result += exam[i].getChoiceResult();
	}

	if (result < 0)
	{
		result = 0;
	}
	system("cls");
	cout << "Your final result is: " << result << "/" << maxResult << ". The test has ended.\n";
	system("pause");

	return 0;
}
