import pandas as pd
import numpy as np

pth='/Users/valerina/PycharmProjects/test/Pandas/'
#pth='C:\\Users\\<user name>\\<папката в която са файловете\\'
fn='invoice_2019_5.xls'
fo='invoice_2019_5_out.xls'
sn='details_1'
df=pd.read_excel(pth+fn,sn)
# pd.read_excel(пълен път до файла,име на листа във файла)

# Извеждане на броя на редовете и колоните
n=df.shape
print(n)

# показва типа на данните от всяка колона
dts=df.dtypes
print(dts)

# Извеждане имената на колоните, достъпни са както списъците
a=df.columns
print(a)
#df.columns=[i for i in range(10)] # преименуване на колоните с цифри от 0 до 9
#print(df.columns)

# връща всички редове (записи, но показва само колоните, които са посочени в списъка
slice_1=df[a[0:3]]
print(slice_1)

# # показва уникалните стойности за колоната, и коя уникална стойност колко пъти се среща
# print(df[a[0]].value_counts())
#
# # първите няколко записа от данните
# h=df.head()
# print(h)
# # последните 5 записа от данните
# print(df.tail(5))
#
# # Кратка статистика за всички данни
# stat=df[a[8]].describe()
# print(stat)
#
# # Сортиране чрез използване на измеренията:редове и колони:
# # axis=1 е по редове
# # axis=0 е по колони
# sorted=slice_1.sort_index(axis=1, ascending=False)
# print(sorted)
# # ????

# Сортиране по стойности чрез използване на името на дадена колона
# print(df.sort_values(by=a[1])) # по дата
#
# # Извежда конкретна колона
# print(df['Избран номер'])
#
# # # Извежда първите 10 реда
# print(df[:10])
# #
# # # Извеждане на конкретни изброени редове, за всички колони
# print(df.loc[[1,5,7],:])
# #
# # # Извеждане на конкретни изброени редове, и конкретни изброени колони
# print(df.loc[[1,5,7],[a[0],a[1]]])
# #
# # # работим само с индекси
# print(df.iloc[3]) # връща всички колони от третия ред
# #
# print(df.iloc[[1,5,7],:2])
# print(df.iloc[[1,5,7],[0,1]])
# #
# # # "всички" се означава с двуеточние :
# # # двуеточието може и да се пропусне, когато искаме да изведем всички колони !!!
# #
# print(df.iloc[[1,5,7],:])
# print(df.iloc[1,2])
# print(df.iat[1,2])

# Съставяне на условия за филтриране на данните, т.нар. WHERE условия
# cond=df.iloc[:,8]>0
# filtered_data=df[cond]
# col=[0,1,3,4,8]
# print(filtered_data.iloc[:,col])
dfna=df.reindex()
cond=dfna.iloc[:,8]>0
filtered_data=dfna[cond].iloc[:,[0,1,3,8]]
sn= 'филтрирани_данни'

filtered_data.to_excel(pth+fo,sheet_name=sn,index=False)



