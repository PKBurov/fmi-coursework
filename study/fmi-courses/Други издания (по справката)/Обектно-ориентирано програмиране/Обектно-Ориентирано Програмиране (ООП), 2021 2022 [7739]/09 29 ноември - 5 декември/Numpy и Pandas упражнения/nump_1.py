import numpy as np
import random as rd

# 1. Напишете Python програма, за да създадете 2D масив с 1-ци на за първия ред,
# последния ред, първата и последната колона и 0-ли в осталата част.
print("Task 1:")
rows=5
cols=10
mat=np.zeros((rows,cols),dtype=int)
mat[0,:]=mat[-1,:]=1
mat[:,0]=mat[:,-1]=1

print(mat)

# 2. Напишете програма Python, за да добавите граница (от 0-ли) около съществуващ масив.
print("Task 2:")
L=[rd.randint(1,100) for i in range(20)]
shape=(5,4)
mat=np.zeros((7,6),dtype=int)
mat[1:-1,1:-1]=np.array(L).reshape(shape)
print(mat)

# 3. Напишете Python програма, за да преобразувате градуси по Целзий в градуси по Фаренхайт.
# Градусите по Целзий се съхраняват в NumPy масив. F = (9 ° С + 32 * 5) / 5
print("Task 3:")
Celsius=[rd.randint(0,100) for i in range(20)]
shape=(5,4)
mat_c=np.array(Celsius).reshape(shape)
print(mat_c)
#mat_f=(mat_c*9+32*5)/5
mat_c[1:4,1:3]=(mat_c[1:4,1:3]*9+32*5)/5
# частична промяна на матрицата, чрез точно указани диапазони за редовете и колоните
print(mat_c)
#print(mat_f)


# 4. Напишете Python програма, за да преобразувате градуси по Фаренхайт в градуси по Целзий.
# Градусите по Фаренхайт се съхраняват в NumPy масив. С = 5 * (F-32) / 9
# Градусите по Целзий се съхраняват в NumPy масив. F = (9 ° С + 32 * 5) / 5
print("Task 4:")
Farenh=[rd.randint(0,100) for i in range(20)]
shape=(5,4)
mat_f=np.array(Farenh).reshape(shape)
mat_c=5*(mat_f-32)
print(mat_c)
print(mat_f)

# 5. Напишете Python програма, за да проверите дали всеки елемент от 1-D масив също присъства във и втория масив.
print("Task 5:")
L_1=[rd.randint(1,100) for i in range(20)]
L_2=[rd.randint(1,100) for i in range(20)]
mat_1=np.array(L_1).reshape(shape)
#mat_2=np.zeros((7,6),dtype=int)
#mat_2[1:-1,1:-1]=mat_1
mat_2=np.array(L_2).reshape(shape)
check=True
for r in range(shape[0]):
    for c in range(shape[1]):
        if mat_1[r,c] not in mat_2:
            check=False
            break
print(mat_1)
print(mat_2)
print(check)

print("Task 6")
# 6. Напишете Python програма, за да намерите общите елементи в два масива.
L_1=[rd.randint(1,100) for i in range(20)]
L_2=[rd.randint(1,100) for i in range(20)]
mat_1=np.array(L_1).reshape(shape)
mat_2=np.array(L_2).reshape(shape)
print(mat_1)
print(mat_2)
common=np.array([i for i in mat_1 if i in mat_2])
# Защо връща грешен отговор ?
print(common)
# или
condition=np.in1d(mat_1, mat_2).reshape(shape)
print(condition)
common=mat_1[condition]
print(common)
# np.in1d(A,B,assume_unique=True) - връща всички елементи от А, които се срещат в B, като
# assume_unique=True означава, че повтарящите се елементи няма да бъдат проверявани и връщани

# или
common=np.intersect1d(mat_1, mat_2) # връща всички елементи от А, които се срещат в B, но сортирани
print(common)



# 7. Напишете Python програма, за да получите уникалните елементи от даден масив.
print("Task 7")
mat_1=np.array([1,2,3,4,5,4,3,2,1,2,3,4])
unique=np.array(list(set(mat_1)))
print(unique)

# 8. Напишете Python програма, за да намерите обединението на два масива.
# Обединението да върне уникалния, сортиран набор от стойности, от двата входни масива.
print("Task 8")
L_1=[rd.randint(1,100) for i in range(20)]
L_2=[rd.randint(1,100) for i in range(20)]
mat_1=np.array(L_1)
mat_2=np.array(L_2)
joined=np.array(list(set(mat_1)|set(mat_2)))
np.sort(joined)
print(mat_1)
print(mat_2)
print(joined)

# 9.  Напишете Python програма, която проверява дали масивът е палиндром
# (т.е. четен в обратен ред същия масив ли се получава)
# ако е с четен брой елементи:
print("Task 9")
L_1=[rd.randint(1,100) for i in range(20)]
mat_1=np.array(L_1)
m_1=mat_1[0:np.size(mat_1)//2]
m_2=mat_1[np.size(mat_1)//2::]
m_2=m_2[::-1] # четене в обратен ред
check=m_1==m_2
print(mat_1)
print(m_1)
print(m_2)
print(check)



# 10. Напишете Python програма, за да създадете 2-D масив с 1-ци по диагонала и нули под и над диагонала.
print("Task 10")
n=5
mat=np.zeros((n,n),dtype=int)
for i in range(n):
    mat[i,i]=1
print(mat)

# 11. Напишете Python програма, за да премахнете всички стойности в масив,
# за които е вярно: 2 * value> value ^ 2. Колко елемента има филтрирания масив?
print("Task 11")
L_1=[rd.randint(1,100) for i in range(20)]
mat_1=np.array(L_1)
print(mat_1)
condition=np.where(2*mat_1 == mat_1**2)
filtered=mat_1[condition]
print(condition)
print(filtered)
print(np.size(filtered))

# 12. Напишете Python програма, която да замени с 1 всички стойности в масив,
# за който е вярно: 2 * value > value +15. Колко елемента са с подменени стойности и колко са 1-ци?
print("Task 12")
L_1=[rd.randint(1,100) for i in range(20)]
mat_1=np.array(L_1)
print(mat_1)
condition=np.where(2*mat_1 > mat_1+15)
print(condition)
mat_1[condition]=1
print(mat_1)
print(np.size(condition))



