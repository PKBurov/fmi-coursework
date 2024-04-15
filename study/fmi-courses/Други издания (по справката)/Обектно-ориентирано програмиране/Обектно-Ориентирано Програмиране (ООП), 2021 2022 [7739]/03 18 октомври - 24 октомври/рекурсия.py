# def arithm_pro_n(a,d,n):
# # n: е n-тия член от аритметична прогресия, който търсим
# # a: е първия член на аритметичната прогресия
# # d: е разликата на аритметичната прогресия
#     if n==1: return a
#     else:
#         return d+arithm_pro_n(a,d,n-1)
# print("n-ти член на аритметична прогресия: " +str(arithm_pro_n(1,2,5)))
#
# def arithm_pro_sum(a,d,n):
# # сума на числата от аритметична прогресия
#     if n==0: return 0
#     else:
#         return a+arithm_pro_sum(a+d,d,n-1)
# print("Сума член на аритметична прогресия: " +str(arithm_pro_sum(1,2,5)))
# #
# def arithm_pro_multiply(a,d,n):
# # произведение на числата от аритметична прогресия
#     if n==1: return a
#     else:
#         return a*arithm_pro_multiply(a+d,d,n-1)
# print("Произведение на аритметична прогресия: " +str(arithm_pro_multiply(1,2,5)))
# #
# def geo_pro_n(a,q,n):
# # n-член от геометрична прогресия
#     if n==1: return a
#     else:
#         return geo_pro_n(a*q,q,n-1)
# print("n-ти член на геометрична прогресия: " +str(geo_pro_n(1,2,5)))
#
# def geo_pro_n(a,q,n):
# # n-член от геометрична прогресия
#     if n==1: return a
#     else:
#         return q*geo_pro_n(a,q,n-1)
# print("n-ти член на геометрична прогресия: " +str(geo_pro_n(1,2,5)))
# def geo_pro_sum(a,q,n):
# # сума на числата от геометрична прогресия
#     if n==1: return a
#     else:
#         return q**(n-1)+geo_pro_sum(a,q,n-1)
# print("Сума на геометрична прогресия: " +str(geo_pro_sum(1,2,5)))
# #
# def geo_pro_multiply(a,q,n):
# # произведение на числата от геометрична прогресия
#     if n==1: return a
#     else:
#         return q**(n-1)*geo_pro_multiply(a,q,n-1)
# print("произведение на геометрична прогресия: " +str(geo_pro_multiply(1,2,5)))
# #
# def rec_list_sum(L):
#     if not L: # L се скъсява на всяко ниво на рекурсия
#         return 0
#     else:
#         return L[0] + rec_list_sum(L[1:])
# print("Сума на числа от списък: "+str(rec_list_sum([1, 2, 4, 8, 16])))
#
# def power(k,n):
# # Лекция 10, слайд 28
# # намира k^n
#   if n==1:
#     return k
#   else:
#     return k * power(k,n-1)
# k=4
# n=3
# print(str(k)+" на "+str(3)+"-та степен: "+str(power(k,n)))

# def len_deep(spis):
#   # Брой на елементите в списък със под-списъци
#   if not spis: return 0
#   else:
#     for elem in spis:
#       if not isinstance(elem,list):
#         return len_deep(spis[1:]) + 1
#       else:
#         return len_deep(elem)+len_deep(spis[1:])
# print("Броят на елементите е: "+str(len_deep(([1, [2, [3, 4]]]))))

# def fibonacci(n):
# # Извежда n-тото число на Фибоначи
#    if n==0: return 0
#    elif n==1: return 1
#    else:
#       return fibonacci(n-1) + fibonacci(n-2)
# print("Числото на Фибоначи с позиция n="+str(6)+" e: "+str(fibonacci(6)))
#
#
# def fib_2(n):
# # извежда първите n числа на Фибоначи
#     global L
#     if n<=1:
#         return L
#     else:
#         L.append(sum(L[-2:]))
#         return fib_2(n-1)
# L = [0, 1]
# F=fib_2(10)
# print("Числата на Фибоначи са: ", F)


def isPalindrome(s):
    # Проверява дали стрингът е палиндром без значение дали буквите са малки или големи
    def toChars(s):
      s = s.lower()
      ans = ''
      for c	in s:
        if c in 'abcdefghijklmnopqrstuvwxyz':
          ans = ans + c
      return ans
    # s='Acds1dca'
    # toChars(s):
    # s='acds1dca'
    # ans='acdsdca'

    def isPal(s):
      if len(s) <= 1: return True
      else:
        return s[0] == s[-1] and isPal(s[1:-1])
    return isPal(toChars(s))
print("Палиндром ли е: "+str(isPalindrome('Acds1dca')))


def isPal(s):
    if len(s) <= 1:
        return True
    else:
        return s[0] == s[-1] and isPal(s[1:-1])
print("Палиндром ли е: "+str(isPal('Acds1dca')))
print("Палиндром ли е: "+str(isPal('Acdsdca')))

def fact(n):
# Намиране на n факториел или n!
    if n == 1:
        return 1
    else:
        return n*fact(n-1)
print(fact(4))