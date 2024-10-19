l=[1,2,3,0,4,5,0]
k=[]
# for i in range(len(l)):
#     try:
#         m=round(l[i]/l[i+1],2)
#     except:
#         m=-1
#     finally:
#         k.append(m)
# print(k)
# # [0.5, 0.67, -1, 0.0, 0.8, -1, -1]

# for i in range(len(l)):
#     try:
#         m=round(l[i]/l[i+1],2)
#     except:
#         m=-1
#     k.append(m)
# print(k)
# [0.5, 0.67, -1, 0.0, 0.8, -1, -1]

# for i in range(len(l)):
#     try:
#         m=round(l[i]/l[i+1],2)
#     except:
#         pass
#     k.append(m)
# print(k)
# # [0.5, 0.67, 0.67, 0.0, 0.8, 0.8, 0.8]
# командата pass не прави нищо, и затова когато има изключение
# към k се добавя елемент със стойност равна на последната изчислена за m

# for i in range(len(l)):
#     try:
#         m=round(l[i]/l[i+1],2)
#         k.append(m)
#     except:
#         pass
# print(k)
# [0.5, 0.67, 0.0, 0.8]

# for i in range(len(l)):
#     try:
#         m=round(l[i]/l[i+1],2)
#         k.append(m)
#     except:
#         pass
#     else:
#         k.append(17)
#         # за всеки възможен try, освен резултата от try се изпълняват и командите в клаузата else
# print(k)
# # [0.5,   17, 0.67, 17,  0.0, 17, 0.8, 17]

# for i in range(len(l)):
#     try:
#         l[i]/l[i+1]
#     except:
#         pass
#     else:
#         m = round(l[i] / l[i + 1], 2)
#         k.append(m)
#         # за всеки възможен try, освен резултата от try се изпълняват и командите в клаузата else
# print(k)
# # [0.5, 0.67, 0.0, 0.8]

# try: print(3/0)
# except ZeroDivisionError: print('Деление на 0')
# else: print("няма грешки")
# finally:print("Край!")

# l=[10,9,8,7,6]
# class CustomError(Exception):
#     """Base class for exceptions in this module."""
#     pass
# n=True
# for i in range(len(l)-1):
#     try:
#         if l[i]<l[i+1]:
#             n=False
#             raise CustomError()
#         else:pass
#
#     except CustomError:
#         print('Редицата не е намаляваща...')
#         break
# if n: print('Редицата е намаляваща')

# # Алтернативен вариант без try/except/raise
# n=True
# for i in range(len(l)-1):
#     if l[i]<l[i+1]:
#         n=False
#         print('Редицата не е намаляваща...')
#         break
# if n: print('Редицата е намаляваща')

# Друг пример за потребителски дефинирани изключения
# import sys
# class FooError(Exception):
#     """Base class for exceptions in this module."""
#     pass
# def foobar (x):
#     if x < 0:
#         raise FooError()
# try:
#     foobar(-1)
# except FooError:
#     print('Uh oh, foo error!')
#     sys.exit()

# Да се въведат от клавиатурата 5 цели числа, по-големи от 5
# i=0
# k=[]
# while i<5:
#     try:
#         m=int(input())
#     except:
#         pass
#     else:
#         if m>5:
#             k.append(m)
#             i+=1
# print(k)

# Дефиниране на функция, която проверява дали дадена друга функция връща греша или не, чрез използване
# на try/except в тялото на функцията. Форматът на използване е: ako f(x), то проверката дали f(x)
# ще може да се изпълни ще бъде iserror(f,x)
# def iserror(func, *args, **kw):
#     try:
#         func(*args, **kw)
#         return False
#         # т.е. Не, не връща грешка
#     except Exception:
#         return True
#         # т.е. Да, връща грешка
# i=0
# k=[]
# while i<5:
#     f=input()
#     m=iserror(int,f)
#     if m==False:
#         if int(f)>5:
#             k.append(int(f))
#             i+=1
# print(k)

# задача: да се намери средното на всички елементи от списъка, които са числа
l=[1,2,3,'0',4,5,'0']

# try/except върху mean(l)
# isinstance(l[i],int) or isinstance(l[i],float)

# try:
#     mean=round(sum(l)/len(l),2)
# except:
#     for i in range(len(l)-1):
#         if isinstance(l[i],str):l.pop(i)
#     mean=round(sum(l)/len(l),2)
# finally:
#     print(mean)

# задача: да се намери средното на всички елементи от списъка, които са числа
# ако има елементи от тип стринг, да се вземе:
# ако е възможно int стойностостта
# ако е възможно float стойностостта
# кода на стринга
# ако не е възможно, да се пропуснат
l=[1,2,3,'0',4,5,'0','u','jk']

# try/except върху mean(l)
# isinstance(l[i],int) or isinstance(l[i],float)
f=[]
# try:
#     sum(l)
# except:
#     for i in range(len(l)):
#         if isinstance(l[i],str):k.append(l[i])
#     if len(k)>0:
#         for i in k:
#             l.remove(i)
#     print(l)
#     print(k)
#     if len(k)>0:
#         for i in range(len(k)):
#             try: int(k[i])
#             except:
#                 try: float(k[i])
#                 except:
#                     try: ord(k[i])
#                     except:f.append(k[i])
#                     else: k[i]=ord(k[i])
#                 else:
#                     k[i]=float(k[i])
#             else:
#                 k[i]=int(k[i])
#         print(k)
#         if len(f)>0:
#             for i in f:
#                 k.remove(i)
#         mean=round((sum(l)+sum(k))/(len(l)+len(k)),2)
#     else:
#         mean=round(sum(l)/len(l),2)
# else:
#     mean = round(sum(l) / len(l), 2)
# finally:
#     print(mean)

# алтернатовно решение 1
print(l)
s=0
n=0
#Събиране първо на всички числа
# for i in l:
#     try: s=s+i
#     except: pass
#     else:
#         f.append(i)
#         n+=1
# for i in f:
#     l.remove(i)
#
# if len(l)>0:
#     f=[]
#     #Събиране първо на int(l) числа
#     for i in l:
#         try: s=s+int(i)
#         except: pass
#         else:
#             f.append(i)
#             n += 1
#     for i in f:
#         l.remove(i)
#
# if len(l)>0:
#     #Събиране първо на float(l) числа
#     f=[]
#     for i in l:
#         try: s=s+float(i)
#         except: pass
#         else:
#             f.append(i)
#             n += 1
#     for i in f:
#         l.remove(i)
#
# if len(l)>0:
#     #Събиране първо на ord(l) числа
#     for i in l:
#         try: s=s+ord(i)
#         except: pass
#         else: n+=1
#
# print(s,round(s/n,2))

# алтернатовно решение 2
l=[1, 2, 3, '0', 4, 5, '0', 'u', 'jk']
f=[]
n,s=0,0
def tryex(func):
    global l,f,n,s
    if len(l) > 0:
        # Събиране първо на float(l) числа
        f = []
        for i in l:
            try:
                s = s + func(i)
            except:
                pass
            else:
                f.append(i)
                n += 1
        for i in f:
            l.remove(i)
tryex(int)
tryex(float)
tryex(ord)
print(s, round(s / n, 2))