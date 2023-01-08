-- USE MOVIES
-- -- Напишете заявка, която извежда адреса на студио ‘Disney’ (Task 1)
--SELECT ADDRESS
--FROM STUDIO
--WHERE NAME='Disney'
---- Напишете заявка, която извежда рождената дата на актьора Jack Nicholson (Task 2)
--SELECT BIRTHDATE
--FROM MOVIESTAR
--WHERE NAME = 'Jack Nicholson' 
---- Напишете заявка, която извежда имената на актьорите, които са участвали във филм от 1980 или във филм, в чието заглавие има думата ‘Knight’ (task 3)
--SELECT STARNAME
--FROM STARSIN
--WHERE MOVIEYEAR = 1980 OR MOVIETITLE = 'Knight'
---- Напишете заявка, която извежда имената на продуцентите с нетниактиви над 10 000 000 долара (task 4)
--SELECT NAME
--FROM MOVIEEXEC
--WHERE NETWORTH > 10000000
---- Напишете заявка, която извежда имената на актьорите, които са мъже или живеят на Prefect Rd. (task 5)
--SELECT NAME
--FROM MOVIESTAR
--WHERE ADDRESS = 'Prefect RD.' OR GENDER = 'M'


-------------------Task's from PC
--USE PC
----Напишете заявка, която извежда модел, честота и размер на диска завсички персонални компютри с цена под 1200 долара. Задайтепсевдоними за атрибутите честота и размер на диска, съответно MHz и GB (Task 1)

--SELECT MODEL,SPEED AS MHZ, HD AS GM
--FROM PC
--WHERE PRICE < 1200

----Напишете заявка, която извежда производителите на принтери без повторения (Task 2)

--SELECT DISTINCT MAKER 
--FROM PRODUCT 
--WHERE TYPE = 'Printer'

---- Напишете заявка, която извежда модел, размер на паметта, размер на екран за лаптопите, чиято цена е над 1000 долара (TASK 3)
--SELECT MODEL,RAM,SCREEN
--FROM LAPTOP
--WHERE PRICE > 1000

---- Напишете заявка, която извежда всички цветни принтери (TASK 4)
--SELECT *
--FROM PRINTER 
--WHERE COLOR = 'Y'

----  Напишете заявка, която извежда модел, честота и размер на диска за тези персонални компютри със CD 12x или 16x и цена под 2000 долара. (TASK 5)

--SELECT MODEL, SPEED, HD
--FROM PC
--WHERE CD = '12x' OR CD = '16x' AND PRICE < 2000

------Experiment
----SELECT MAKER FROM PRODUCT
----WHERE TYPE = 'Laptop' AND MAKER NOT IN 
----(SELECT DISTINCT MAKER 
----FROM PRODUCT
----WHERE TYPE = 'PC');

----- ----------TASK'S FROM SHIPS
--USE SHIPS
----Напишете заявка, която извежда класа и страната за всички класове с помалко от 10 оръдия.
--SELECT CLASS, COUNTRY 
--FROM CLASSES
--WHERE NUMGUNS < 10

---- Напишете заявка, която извежда имената на корабите, пуснати на вода преди 1918. Задайте псевдоним shipName на колоната.

--SELECT NAME AS SHIPNAME
--FROM SHIPS
--WHERE LAUNCHED < 1918

---- Напишете заявка, която извежда имената на корабите, потънали в битка и имената на съответните битки.

--SELECT SHIP, BATTLE
--FROM OUTCOMES
--WHERE RESULT = 'sunk'

---- Напишете заявка, която извежда имената на корабите с име, съвпадащо с името на техния клас.
--SELECT NAME
--FROM SHIPS
--WHERE CLASS = NAME

---- Напишете заявка, която извежда имената на корабите, които започват с буквата R.
--SELECT NAME 
--FROM SHIPS
--WHERE NAME LIKE 'R%'

---- Напишете заявка, която извежда имената на корабите, които съдържат 2 или повече думи.
--SELECT NAME 
--FROM SHIPS 
--WHERE NAME LIKE '% %'

-- Упражнение 2 
--USE MOVIES

-- Напишете заявка, която извежда имената на актьорите мъже, участвали във филма The Usual Suspects.--SELECT NAME--FROM STARSIN, MOVIESTAR,--WHERE GENDER = 'M' AND MOVIETITLE = 'The Usual Suspects' AND STARNAME = NAME;--Напишете заявка, която извежда имената на актьорите, участвали във филми от 1995, продуцирани от студио MGM--SELECT DISTINCT STARSIN.STARNAME --FROM MOVIE, STARSIN, STUDIO--WHERE MOVIE.YEAR=STARSIN.MOVIEYEAR AND MOVIE.YEAR = 1995 AND MOVIE.STUDIONAME = 'MGM'--Напишете заявка, която извежда имената на продуцентите, които са продуцирали филми на студио MGM.--SELECT DISTINCT MOVIEEXEC.NAME--FROM MOVIEEXEC, MOVIE--WHERE STUDIONAME = 'MGM' AND PRODUCERC# = CERT#;-- Напишете заявка, която извежда имената на филми с дължина, по-голяма от дължината на филма Star Wars.--SELECT M1.TITLE--FROM MOVIE AS M1, MOVIE AS M2--WHERE M1.LENGTH > M2.LENGTH AND M2.TITLE = 'Star Wars'	--Напишете заявка, която извежда имената на продуцентите с нетни активи поголеми от тези на Stephen Spielberg.--SELECT M1.NAME--FROM MOVIEEXEC as M1, MOVIEEXEC as M2--WHERE M1.NETWORTH > M2.NETWORTH AND M2.NAME = 'Stephen Spielberg'-- Напишете заявка, която извежда имената на всички филми, които са продуцирани от продуценти с нетни активи по-големи от тези на Stephen Spielberg.--SELECT dbo.MOVIE.TITLE--FROM dbo.MOVIE,dbo.MOVIEEXEC as E1,dbo.MOVIEEXEC AS E2	--WHERE E2.NAME= 'Stephen Spielberg' AND e1.NETWORTH > e2.NETWORTH AND PRODUCER# = e1.CERT#?-- С PC--USE PC-- Напишете заявка, която извежда производителя и честотата на лаптопите с размер на диска поне 9 GB.--SELECT DISTINCT MAKER,SPEED--FROM PRODUCT,LAPTOP--WHERE SPEED >= 9 AND HD >= 9-- Напишете заявка, която извежда модел и цена на продуктите, произведени от производител с име B.--SELECT PRODUCT.MAKER --FROM PRODUCT, LAPTOP,PC,PRINTER--WHERE PRODUCT.MAKER = 'B' AND PRODUCT.MODEl = PRINTER.MODEL--Напишете заявка, която извежда производителите, които произвеждат лаптопи, но не произвеждат персонални компютри.--Напишете заявка, която извежда размерите на тези дискове, които се предлагат в поне два различни персонални компютъра (два компютъра с различен код).--SELECT DISTINCT M1.hd--FROM PC AS M1, PC AS M2--WHERE M1.CODE != M2.CODE and M1.HD = M2.HD---- Напишете заявка, която извежда двойките модели на персонални компютри, които имат еднаква честота и памет. Двойките трябва да се показват само по	веднъж, например само (i, j), но не и (j, i).--SELECT M1.MODEL,M2.MODEL--FROM PC as M1, PC AS M2--WHERE M1.SPEED = M2.SPEED and M1.RAM = M2.RAM and M1.MODEL < M2.MODELUSE SHIPS-- Напишете заявка, която извежда името на корабите с водоизместимост над 50000SELECT DISTINCT SHIPS.NAMEFROM SHIPS,CLASSESWHERE SHIPS.CLASS = CLASSES.CLASS AND DISPLACEMENT > 50000