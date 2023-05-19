###
# zad88
alco <- read.table("bac.txt", header=T)

# a)
m1 <- lm( bac ~ beers, data=alco )
m1
# y = съдържание на алкохол в кръвта (bac)
# x = брой изпити бутилки бира (beers)
# модел:
# y = beta0 + beta1*x + eps
# [ bac = beta0 + beta1*beers + eps ]
# оценено регресионно уравнение:
# y.hat = -0.01270 + 0.01796*x

plot( bac ~ beers, data=alco )
abline( coef(m1), lwd=2 )

# графика на остатъците срещу y.hat
plot( fitted(m1), resid(m1) )

# б)
# При изпиване на още една бира съдържанието на алкохол в кръвта
# се увеличава средно с 0.01796.
# 
# При нула изпити бири средното съдъжание на алкохол в кръвта е -0.01270.

# в)
# H0: beta1 = 0
# H1: beta1 != 0

summary(m1)
summary(m1)$coefficients
p.value <- summary(m1)$coefficients[2,4]
p.value < 0.05

# p.value < 0.05 => отхвърляме H0.
# Можем да твърдим, че има линейна връзка между броя на 
# изпитите бутилки бира и съдържанието на алкохол в кръвта.

# г)
# H0: beta1 = 0.02
# H1: beta1 != 0.02

# доверителни интервали (ДИ) за beta0 и beta1
confint(m1)

# 0.02 е в ДИ [0.0128, 0.0231] за beta1 => не отхвърляме H0.
# Нямаме основания да отхвърлим хипотезата, че при изпиването на 
# още една бира съдържанието на алкохол в кръвта се увеличава 
# средно с 0.02.

# д)
predict( m1, data.frame( beers=c(5) ), interval="confidence" )
predict( m1, data.frame( beers=5 ), interval="confidence" )

# [ -0.01270 + 0.01796*5 = fit ]
# 
# Доверителният интервал е [0.066, 0.088]

# е)
plot( bac ~ beers, data=alco )
abline( coef(m1), lwd=2 )

xx <- data.frame( beers=seq(1, 9, 0.5) )

# доверителни интервали
cint <- predict( m1, xx, interval="confidence" )
lines( xx$beers, cint[,2], type="l", lty="dotted", lwd=2 )
lines( xx$beers, cint[,3], type="l", lty="dotted", lwd=2 )

# интервали за прогноза
pint <- predict( m1, xx, interval="prediction" )
lines( xx$beers, pint[,2], type="l", lty="dotted", col="gray", lwd=2 )
lines( xx$beers, pint[,3], type="l", lty="dotted", col="gray", lwd=2 )


###
# zad89

# a)
set.seed(12)
n <- 50
beta0 <- 2
beta1 <- 1.5
sigma <- 2
x <- runif(n, 1, 7)
eps <- rnorm(n, 0, sigma)
y <- beta0 + beta1*x + eps

m1 <- lm(y~x)
plot(x, y)
abline( coef(m1), lwd=2 )
abline( a=beta0, b=beta1, col="coral", lwd=2 )

summary(m1)
summary(m1)$r.squared
confint(m1)

# б)
set.seed(12)
n <- 50
beta0 <- 2
beta1 <- 1.5
sigma <- 1
x <- runif(n, 1, 7)
eps <- rnorm(n, 0, sigma)
y <- beta0 + beta1*x + eps

m2 <- lm(y~x)
plot(x, y)
abline( coef(m2), lwd=2 )
abline( a=beta0, b=beta1, col="coral", lwd=2 )

summary(m2)
summary(m2)$r.squared
confint(m2)

# в)
set.seed(12)
n <- 50
beta0 <- 2
beta1 <- 0.17
sigma <- 1
x <- runif(n, 1, 7)
eps <- rnorm(n, 0, sigma)
y <- beta0 + beta1*x + eps

m3 <- lm(y~x)
plot(x, y, ylim=c(0,13))
abline( coef(m3), lwd=2 )
abline( a=beta0, b=beta1, col="coral", lwd=2 )

summary(m3)
summary(m3)$r.squared
confint(m3)


###
# zad90
set.seed(12)
n <- 50
beta0 <- 2
beta1 <- 1.1
sigma <- 2.5
x <- runif(n, 1, 7)
eps <- rnorm(n, 0, sigma)
y <- beta0 + beta1*x^2 + eps

m4 <- lm(y~x)
plot(x, y)
abline( coef(m4), lwd=2 )

summary(m4)
summary(m4)$r.squared
confint(m4)

plot( fitted(m4), resid(m4) )


###
# zad91
satgpa <- read.table("satgpa.txt", header=T)

# scatter plot matrix
pairs( satgpa, gap=0, cex.labels=0.9 )

# а)
m1 <- lm( fy_gpa ~ hs_gpa, data=satgpa )
m1
# y = успех от първата година в колежа (fy_gpa)
# x = успех от гимназията (hs_gpa)
# модел:
# y = beta0 + beta1*x + eps
# оценено регресионно уравнение:
# y.hat = 0.09132 + 0.74314*x

plot( fy_gpa ~ hs_gpa, data=satgpa )
abline( coef(m1), lwd=2 )

# графика на остатъците срещу y.hat
plot( fitted(m1), resid(m1) )

# б)
# Успех от гимназията по-висок с 1 съответства на 
# успех от първата година в колежа по-висок средно с 0.74314.

# H0: beta1 = 0
# H1: beta1 != 0
summary(m1)
p.value <- summary(m1)$coefficients[2,4]
p.value < 0.05 
# => отхвърляме H0.
# Можем да твърдим, че има линейна връзка между успеха от гимназията
# и успеха от първата година в колежа.

# в)
# доверителен интервал
predict( m1, data.frame( hs_gpa=3.5 ), interval="confidence" )

# интервал за прогноза
predict( m1, data.frame( hs_gpa=3.5 ), interval="prediction" )

# г)
m2 <- lm( fy_gpa ~ hs_gpa + sat_sum, data=satgpa )
summary(m2)
plot( fitted(m2), resid(m2) )

m3 <- lm( fy_gpa ~ hs_gpa + sat_m, data=satgpa )
summary(m3)
plot( fitted(m3), resid(m3) )

m4 <- lm( fy_gpa ~ hs_gpa + sat_v, data=satgpa )
summary(m4)
plot( fitted(m4), resid(m4) )

summary(m1)$adj.r.squared
summary(m2)$adj.r.squared
summary(m3)$adj.r.squared
summary(m4)$adj.r.squared
# Моделът m2 има най-голям adj.r.squared => е най-добър от трите
# (ако считаме, че моделът с най-висок adj.r.squared е най-добър).


###
# zad92
cher <- read.table("cherry.txt", header=T)
# scatter plot matrix
pairs( cher, gap=0, cex.labels=0.9 )

# а)
m1 <- lm( volume ~ diam, data=cher )
m1
# y = обем (volume)
# x = диаметър (diam)
# модел:
# y = beta0 + beta1*x + eps
# оценено регресионно уравнение:
# y.hat = -36.943 + 5.066*x

plot( volume ~ diam, data=cher )
abline( coef(m1), lwd=2 )

summary(m1)
plot( fitted(m1), resid(m1) )

# б)
# Ако диаметърът е по-голям с 1 инч, 
# обемът ще е по-голям средно с 5.066 кубични фута.

# в)
m2 <- lm( volume ~ diam + height, data=cher )
m2
# y = обем (volume)
# x1 = диаметър (diam)
# x2 = височина (height)
# модел:
# y = beta0 + beta1*x1 + beta2*x2 + eps
# оценено регресионно уравнение:
# y.hat = -57.9877 + 4.7082*x1 + 0.3393*x2

summary(m2)
plot( fitted(m2), resid(m2) )

# Ако диаметърът е по-голям с 1 инч при фиксирана височина, 
# обемът ще е по-голям средно с 4.7082 кубични фута.

# Ако височината е по-голяма с 1 фут при фиксиран диаметър, 
# обемът ще е по-голям средно с 0.3393 кубични фута.

# г)
ci.g <- predict( m2, data.frame( diam=14, height=70 ), interval="confidence" )
ci.g

# д)
cher$diam2 <- cher$diam^2
m3 <- lm( volume ~ diam2 + height, data=cher )
summary(m3)
plot( fitted(m3), resid(m3) )

ci.d <- predict( m3, data.frame( diam2=14^2, height=70 ), interval="confidence" )
ci.d

# Доверителният интервал с модел m3 е по-къс:
ci.g[3] - ci.g[2]
ci.d[3] - ci.d[2]

summary(m1)$adj.r.squared
summary(m2)$adj.r.squared
summary(m3)$adj.r.squared
# Моделът m3 има най-голям adj.r.squared

# Друг начин да включим квадрата на диаметъра:
m4 <- lm( volume ~ I(diam^2) + height, data=cher )
predict( m4, data.frame( diam=14, height=70 ), interval="confidence" )


###
# zad93
duke <- read.csv("duke_forest.csv", header=T)
pairs( duke[,c(2,3,4,5,7,11)], gap=0, cex.labels=0.9 )

# backward elimination:
# Построяваме модел включващ всички възможни предиктори.
# Премахваме предиктора с най-голямо p.value докато получим модел,
# в който всички предиктори имат p.value < 0.05.

options(scipen=999)

m01 <- lm( price ~ bed + bath + area + year_built + lot, data=duke )
summary(m01)$coefficients

m02 <- lm( price ~ bath + area + year_built + lot, data=duke )
summary(m02)$coefficients

m03 <- lm( price ~ bath + area + lot, data=duke )
summary(m03)$coefficients

# Получаваме модел m3 като резултат от backward elimination.

# Друг подход:
# В модела не е желателно да има предиктори, които са силно корелирани.
# От корелационната матрица виждаме, че bed, bath и area са силно корелирани помежду си.
cor( duke[,c(3,4,5)], use="complete.obs" )

# Затова в модела може да включим само една от променливите bed, bath и area, 
# като запазим year_built + lot.

m21 <- lm( price ~ area + year_built + lot, data=duke )
summary(m21)$coefficients

m22 <- lm( price ~ bed + year_built + lot, data=duke )
summary(m22)$coefficients

m23 <- lm( price ~ bath + year_built + lot, data=duke )
summary(m23)$coefficients

summary(m21)$adj.r.squared
summary(m22)$adj.r.squared
summary(m23)$adj.r.squared

# От горните три модела, m21 има най-голям adj.r.squared. 
# В модела m21 всички предиктори имат p.value < 0.05.

# Ако сравним adj.r.squared на m21 и m03, ще видим, че не се различават съществено.
summary(m03)$adj.r.squared


###
# zad94
sim.lm.a <- function(n) {
  x <- runif(n, 1, 10)
  y <- 2 + 5*x + rnorm(n, 0, 5) 
  m1 <- lm(y~x)
  c( coef(m1)["x"], confint(m1, "x"), use.names=F )
}

sim.lm.b <- function(n) {
  x <- runif(n, 1, 10)
  y <- 2 + 5*x + rexp(n, 1/5)
  m1 <- lm(y~x)
  c( coef(m1)["x"], confint(m1, "x"), use.names=F )
}

smry <- function(rs) {
  mean.b1.hat <- mean( rs[1,] )
  ci.coverage <- sum( rs[2,] <= 5 & 5 <= rs[3,] ) / ncol(rs)
  mean.ci.len <- mean( rs[3,] - rs[2,] )
  c(mean.b1.hat, ci.coverage, mean.ci.len)
}


res.a.30 <- replicate( 10000, sim.lm.a(30) )
res.b.30 <- replicate( 10000, sim.lm.b(30) )

smry(res.a.30)
smry(res.b.30)

res.a.50 <- replicate( 10000, sim.lm.a(50) )
res.b.50 <- replicate( 10000, sim.lm.b(50) )

smry(res.a.50)
smry(res.b.50)

res.a.100 <- replicate( 10000, sim.lm.a(100) )
res.b.100 <- replicate( 10000, sim.lm.b(100) )

smry(res.a.100)
smry(res.b.100)

res.a.500 <- replicate( 10000, sim.lm.a(500) )
res.b.500 <- replicate( 10000, sim.lm.b(500) )

smry(res.a.500)
smry(res.b.500)


###
