# ПРИМЕР 1: Вложена анонимна функция в потребителски дефинирана функция
# def knights():
# 	title = 'Sir'
# 	action = (lambda x: title + ' ' + x)
# 	# title в lambda е от тялото на външната дефиниция
# 	return action # връща обект функция
# act = knights()
# #print(act)
# # act: обект тип функция, всъщност това е lambda функцията, която очаква да й бъде подаден аргумент
# msg = act('Robin')
# # 'Robin' се подава на lambda функцията като аргумент
# print(msg)


# # ПРИМЕР 2: анонимна функция
# L = [lambda x: x ** 2, lambda x: x ** 3,lambda x: x ** 4]
# # Списък с 3 анонимни функции
# for f in L:
#     print(f(2)) # Извежда 4, 8, 16
# print(L[0](3)) # Извежда 9

# # ПРИМЕР 3: анонимна функция
# key = 'got'
# x=int(input("Въведете цяло число: "))
# #res={'already': (lambda x: x + 2), 'got': (lambda x: x*4),'one': (lambda x: x ** 6)}[key](x)
# dic={'already': (lambda x: x + 2), 'got': (lambda x: x*4),'one': (lambda x: x ** 6)}
# res=dic[key](x)
# # {'already': (lambda x: x + 2), 'got': (lambda x: x*4),'one': (lambda x: x ** 6)}[key]  ТОВА ВРЪЩА СТОЙНОСТТА ЗА КЛЮ§А got,
# # който е функцията lambda x: x*4
# # със (x) подаваме на ламбда въведената стойност от клавиатурата
# print(res)


# # ПРИМЕР 4: Вложени анонимни функции в други анонимни функции
# action = (lambda x: (lambda y: x + y))
# act = action(99) # задава външния параметър x и очаква да се подаде y
# a=act(3) # задава вътрешния параметър y и изчислява целия израз
# print(a)
# xy=action(99)(3)
# # action(99) връща вложената ламбда функция със x=99 и очаква да подадем стойността за y
# # action(99)(3) връща резултата от прилагането на вътрешната и външната ламбда функции
# print(xy)

# #ПРИМЕР 4: функции от тип Обвивки (Closure) - потребителски дефинирани сключовата дума def
# def build_taxer(rate):
# 	def taxer(amount):
# 		return round(amount * (float(rate) / 100),2)
# 	return taxer # в ретърна стои името на вътрешната функция
# vat1 = build_taxer(22) # rate=22
# vat2 = build_taxer(7)  # rate=7
# amount=10
# print(vat1(amount))
# print(vat2(amount))
# print(build_taxer(22)(10))

# #ПРИМЕР 5: map - прилага функцията върху всички елементи от контейнера
# print(list(map(lambda x: x**2, range(1,5))))
# # формат на функцията map: map(функция,контейнер)
# # функцията от map-a се изпълнява за всяка една стойност от контейнера,
# # т.е. елементите на контейнера се подават като аргументи на функцията
# # еквивалентен запис:
# L=[x**2 for x in range(1,5)]
# print(L)
# # 1,4,9,16

# #ПРИМЕР 6:
# def f(x):
#     def g(x): return x**1
#     def z(x): return x**(-1)
#     if x>=0: return g(x)
#     else: return z(x)
#
# import time
# import random
#
# x=[random.randint(-100,100)for x in range(1000000)]
#
# t1=time.time()
# k=[f(y) for y in x]
# # реално k представлява списък от функции, с аргумент поредното x от списъка x
# t2=time.time()
# a=list(map(f,x)) # аналог на ред 79
# t3=time.time()
# print(t1,'\n',t2,'\n',t3)
# print('време за изпълнение на цикъл: '+str(round(t2-t1,4)))
# print('време за изпълнение на map: '+str(round(t3-t2,4)))

# # ПРИМЕР 7:
# def f(x): return x % 2 != 0 and x % 3 != 0 # TRUE означава в случая ДА НЕ СЕ ДЕЛИ ТОЧНО
# a=list(filter(f, range(2, 25)))
# # формат на функцията filter: filter(функция или условие, контейнер)
# # Е РАЗЛИЧНО ОТ:
# def g(x): return x % 6 != 0 # ДА НЕ СЕ ДЕЛИ ТОЧНО
# # защото "да не се дели на 6, означава че може и да се дели или само на 2 или само 3, или на нито едно от двете
# b=list(filter(g, range(2, 25)))
#
# print(a)
# print(b)
# if a==b: print("еднакъв резултат")
# else: print("различен резултат, т.е. x % 2 != 0 and x % 3 != 0 е различно от x % 6 != 0")

# ПРИМЕР 8:
from functools import reduce
# def factorial1(n):
# 	def mult(a,b): return a*b
# 	return reduce(mult, range(1,n+1))
# # формат на reduce: reduce (функция, контейнер)
# # reduce връща едно число
# # стъпка 1: взима от контейнера първите два елемента и прилага върху тях функцията
# # на всяка следваща стъпка: взима резултата от предходната стъпка и
# # поредния елемент от контейнера, и върху тях прилага функцията
# print(factorial1(5)) # Връща 120, т.е. 1*2*3*4*5, защото реално range(1,5+1) е все едно числата от 1 до 5 включително

# # еквивалентен запис чрез цикъл FOR
# n=5
# p=1
# for i in range(1,n+1):
# 	p=p*i
# print(p)

# ПРИМЕР 9:
# def factorial1(l):
# 	def mult(a,b): return a*b
# 	return reduce(mult,l,1)
# 	# ако списъкът l е празен, то mult ще върне стойност 1
# l=[]
# print(factorial1(l)) # резултат 1, това е стойността по подразбиране ако списъкът е празен, и е 3-тия параметър в reduce

# ПРИМЕР 10:
# използваме функцията от Пример 8 factorial1
def factorial1(n):
	def mult(a,b): return a*b
	return reduce(mult, range(1,n+1))
ll=[n for n in range(1,11)]
zipped=zip(ll,list(map(factorial1,ll)))
print(list(zipped))
# необходимо е ll да бъде конвертиран до списъл чрез list(), за да може да се използва от map