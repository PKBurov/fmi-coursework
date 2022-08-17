###
# zad2
x <- c(5, 20, 0, 10, 10, 25, 5, 15, 0, 20)
m <- matrix( x, nrow=5, ncol=2, byrow=T )
m

colnames(m) <- c("X1", "X2")

m[ order(m[,1]), ]
m[ order(m[,1], m[,2]), ]
m <- m[ order(m[,1], m[,2]), ]

df <- as.data.frame(m)
df$X3 <- c(1, 7,-1,-5, 8)
df

df$X4 <- ifelse( df$X3>0, "A", "B" )

df$X5 <- c(5, 3, 6, NA, NA)

df$X5 <- replace( df$X5, is.na(df$X5), 99 )
# df <- replace( df, is.na(df), 99 )

df[ df$X3>5, c("X1", "X2") ]
# df[ df$X3>5, c('X1', 'X2') ]


###
# zad3
getwd()
load("pi2000.RData")

# library(UsingR)
# data(pi2000)

hist(pi2000, col="gray")
hist(pi2000, col="gray", breaks=c(-1,0:9))
table(pi2000)
barplot(table(pi2000))


###
# zad4
library(MASS)
data(survey)

# a
table(survey$Sex)
summary(survey$Sex)
sum( survey$Sex=="Female" )
sum( survey$Sex=="Female", na.rm=T )

# b
table( survey$Sex, survey$Smoke )
sum( survey$Sex=="Female" & survey$Smoke=="Never", na.rm=T )

# v
attach(survey)
mean( Pulse[Sex=="Female"], na.rm=T )

# g, d
mean( Pulse[Age<25], na.rm=T )
mean( Pulse[Age>=25], na.rm=T )

# e
survey[ order(Age)[1:5] , c("Age", "Smoke") ]
sort(Age)[1:5]

# zh
survey[ order(Age)[1] , c("Pulse") ]
Pulse[ which.min(Age) ]


###
# zad5
# a
options(digits=3)
prop.table( table(Smoke) )
prop.table( table(Smoke) )[2]
prop.table( table(Smoke) )["Never"]

# b
prop.table( table(Smoke, Sex) )
prop.table( table(Smoke, Sex) )[2,1]
prop.table( table(Smoke, Sex) )["Never","Female"]

# v
prop.table( table(Smoke, Sex), 2 )
prop.table( table(Smoke, Sex), 2 )[2,1]

# g
prop.table( table(Smoke, Sex), 1 )
prop.table( table(Smoke, Sex), 1 )[2,1]


###
# zad6
table(Smoke)
barplot( table(Smoke) )
barplot( table(Sex, Smoke), beside=T, legend=T )

Smoke1 <- factor(Smoke, levels=levels(Smoke)[c(2,3,4,1)])
table(Smoke1)
barplot( table(Smoke1) )
barplot( table(Sex, Smoke1), beside=T, legend=T )


###
# zad8
# a
median(Height, na.rm=T)
mean(Height, na.rm=T)
sd(Height, na.rm=T)
mean(Height, na.rm=T) - 3*sd(Height, na.rm=T)
mean(Height, na.rm=T) + 3*sd(Height, na.rm=T)

# b
median(Height[Sex=="Female"], na.rm=T)
mean(Height[Sex=="Female"], na.rm=T)
sd(Height[Sex=="Female"], na.rm=T)
mean(Height[Sex=="Female"], na.rm=T) - 3*sd(Height[Sex=="Female"], na.rm=T)
mean(Height[Sex=="Female"], na.rm=T) + 3*sd(Height[Sex=="Female"], na.rm=T)

# v
median(Height[Sex=="Male"], na.rm=T)
mean(Height[Sex=="Male"], na.rm=T)
sd(Height[Sex=="Male"], na.rm=T)
mean(Height[Sex=="Male"], na.rm=T) - 3*sd(Height[Sex=="Male"], na.rm=T)
mean(Height[Sex=="Male"], na.rm=T) + 3*sd(Height[Sex=="Male"], na.rm=T)


###
# zad9
hist( Height, col="gray" )
boxplot( Height~Sex, col="gray" )
boxplot( Height[Sex=="Female"], Height[Sex=="Male"], col="gray" )


###
# zad11
data(anscombe)
attach(anscombe)

par(mfrow=c(2,2))
plot(x1, y1)
plot(x2, y2)
plot(x3, y3)
plot(x4, y4)

plot(y1~x1)
plot(y2~x2)
plot(y3~x3)
plot(y4~x4)

plot(x1, y1, xlim=c(3,20), ylim=c(3,15))
plot(x2, y2, xlim=c(3,20), ylim=c(3,15))
plot(x3, y3, xlim=c(3,20), ylim=c(3,15))
plot(x4, y4, xlim=c(3,20), ylim=c(3,15))
par(mfrow=c(1,1))

cor(x1, y1)
cor(x2, y2)
cor(x3, y3)
cor(x4, y4)


###
# zad12
# dice

Nrep <- 20000
dice <- sample( c(1:6), Nrep, replace=T )
sum(dice==6)/Nrep

i <- 1:Nrep
r <- ifelse( dice==6, 1, 0 )
freq.six.i <- cumsum(r)/i

cbind( r, csum=cumsum(r), i, freq.six.i )[1:20, ]

plot( i, freq.six.i, type="l", lwd=2.0 )
abline( h=1/6, col="red", lwd=2.0 )


###
# zad13
# gifts

sim.gifts <- function(k) {
  x <- sample( c(1:k), k, replace=F )
  d <- x - c(1:k)
  any(d==0)
}

prob.gifts <- function(Nrep, k) {
  rs <- replicate( Nrep, sim.gifts(k) )
  sum(rs)/length(rs)
}

prob.gifts(100000, 20)

# for large k 
1-1/exp(1)


###
# zad14
# birthdays

sim.bday <- function(k) {
  x <- sample( c(1:365), k, replace=T )
  anyDuplicated(x) > 0
}

prob.bday <- function(Nrep, k) {
  rs <- replicate( Nrep, sim.bday(k) )
  sum(rs)/length(rs)
}

prob.bday(100000, 25)

# other solutions
prob.bday1 = function(Nrep, k) {
  M <- replicate( Nrep, sample( c(1:365), k, replace=T ) )
  v <- apply( M, 2, anyDuplicated )
  sum(v>0)/length(v) 
}

prob.bday2 = function(Nrep, k) {
  M <- replicate( Nrep, sample( c(1:365), k, replace=T ) )
  v <- apply( M, 2, function(x) max(tabulate(x)) )
  sum(v>=2)/length(v) 
} 

prob.bday1(100000, 25)
prob.bday2(100000, 25)


###
# zad15
# exam 20 questions

sim.exam <- function() {
  q <- c( rep(1,3), rep(2,17) )
  x <- sample( q, 2, replace=F )
  sum(x)==3
}

prob.exam <- function(Nrep) {
  rs <- replicate( Nrep, sim.exam() )
  sum(rs)/length(rs)
}

prob.exam(100000)


###
# zad16
# 5 keys

sim.keys <- function() {
  x <- sample( c(1:5), 5, replace=F )
  x[5]==1
}

prob.keys <- function(Nrep) {
  rs <- replicate( Nrep, sim.keys() )
  sum(rs)/length(rs)
}

prob.keys(100000)


### 
# zad17
# three ants

sim.ants <- function() {
  a <- vector("numeric", 3)
  a[1] <- sample( c(2,3), 1 )
  a[2] <- sample( c(1,3), 1 )
  a[3] <- sample( c(1,2), 1 ) 
  all( c(1,2,3) %in% a ) 
}

prob.ants <- function(Nrep) {
  rs <- replicate( Nrep, sim.ants() )
  sum(rs)/length(rs)
}

prob.ants(100000)


###
# zad18
# cards in boxes

sim.bw <- function() { 
  card <- sample( c("bb", "ww", "bw"), 1 )
  side <- sample( c(1,2), 1 )
  up <- substr( card, start=side, stop=side ) 
  c(up, card)
}

prob.bw <- function(Nrep) {
  rs <- replicate( Nrep, sim.bw() )
  sum(rs[2,]=="ww") / sum(rs[1,]=="w") 
}

sim.bw()
prob.bw(100000)


###
# zad23
n <- 10
p <- 1/6

# P(X=2)
dbinom(2, n, p)
choose(n,2)*(p^2)*(1-p)^8

# P(X<=2)
pbinom(2, n, p)
dbinom(0, n, p) + dbinom(1, n, p) + dbinom(2, n, p)

# P(X>=2) = 1 - P(X<=1)
1 - pbinom(1, n, p)


###
# zad24
p <- 1/6

# P(X<=10)
pgeom(10-1, p)

# P(X>=6) = 1 - P(X<=5)
1 - pgeom(5-1, p)


###
# zad25
p <- 1/6
r <- 3

# P(X<=20)
pnbinom(20-r, r, p)


###
# zad26
dhyper(2, 5, 3, 2)
choose(5,2)*choose(3,0)/choose(8,2)


###
# zad27
n <- 1500
p <- 1/500

# P(X<=2)
pbinom(2, n, p)
ppois(2, n*p)

# P(1<=X<=3)
# P(1<=X<=3) = P(X=1) + P(X=2) + P(X=3)
dbinom(1, n, p) + dbinom(2, n, p) + dbinom(3, n, p)
dpois(1, n*p) + dpois(2, n*p) + dpois(3, n*p)

# P(1<=X<=3) = P(X<=3) - P(X<=0)
pbinom(3, n, p) - pbinom(0, n, p)
ppois(3, n*p) - ppois(0, n*p)


###
# zad31
u <- runif( 500, 2, 3)
hist( u, probability=T, col="gray" )
curve( dunif(x, 2, 3), from=2, to=3, add=T, lwd=2 )

u <- runif( 5000, 2, 3)
hist( u, probability=T, col="gray" )
curve( dunif(x, 2, 3), from=2, to=3, add=T, lwd=2 )


###
# zad32
ex <- rexp( 500, 1/7 )
hist( ex, probability=T, col="gray" )
curve( dexp(x, 1/7), from=0, to=max(ex), add=T, lwd=2 )

ex <- rexp( 5000, 1/7 )
hist( ex, probability=T, col="gray" )
curve( dexp(x, 1/7), from=0, to=max(ex), add=T, lwd=2 )


###
# zad33
nr <- rnorm(500, 0, 1)
hist( nr, probability=T, col="gray", xlim=c(-4,4) )
curve( dnorm(x, 0, 1), add=T, lwd=2.5 )

nr <- rnorm(10000, 0, 1)
hist( nr, probability=T, col="gray", xlim=c(-4,4) )
curve( dnorm(x, 0, 1), add=T, lwd=2.5 )


###
# zad34
# X = количество душ гел
# X ~ U(248, 255)
# P(X<250) = P(X<=250)
punif(250, 248, 255)

# v=? : P(X>=v) = 0.95
# P(X<v) = 0.05 
# 0.05-квантил = Q(0.05)
qunif( 0.05, 248, 255 )

# P(X<248.35) 
punif( 248.35, 248, 255 )


###
# zad35
# X = време на живот
# X ~ Exp(1/10)

# P(X>10) = 1-P(X<=10)
1 - pexp(10, 1/10)

# P(7<X<11) = P(X<11) - P(X<7)
pexp(11, 1/10) - pexp(7, 1/10)

# t=? : P(X>t) = 0.97
# P(X<t) = 0.03
qexp(0.03, 1/10)


###
# zad36
# X = време до изтощаване
# X ~ N(mu=260, sigma=50)

# P(X>240) = 1 - P(X<240)
1 - pnorm(240, 260, 50)

# P(180<X<300) = P(X<300) - P(X<180)
pnorm(300, 260, 50) - pnorm(180, 260, 50)

# t=? : P(X>t) = 0.9
# P(X<t) = 0.1
qnorm(0.1, 260, 50)


###
# zad37
# X ~ Exp(1/5)
# P(X>10) = 1-P(X<10)
1 - pexp(10, 1/5)

# t=? : P(X<t) = 0.5
qexp(0.5, 1/5)


###
# zad41
Nrep <- 7000

e10   <- replicate( Nrep, rexp(  10, 1/5) )
e50   <- replicate( Nrep, rexp(  50, 1/5) )
e100  <- replicate( Nrep, rexp( 100, 1/5) )
e500  <- replicate( Nrep, rexp( 500, 1/5) )
e5000 <- replicate( Nrep, rexp(5000, 1/5) )

m.e10   <- apply(e10  , 2, mean)
m.e50   <- apply(e50  , 2, mean)
m.e100  <- apply(e100 , 2, mean)
m.e500  <- apply(e500 , 2, mean)
m.e5000 <- apply(e5000, 2, mean)

pdf(file="z_boxplot_mean_exp_.pdf", width=7.0, height=4.5)
par(mai=c(0.5, 0.5, 0.5, 0.1))
boxplot( m.e5000, m.e500, m.e100, m.e50, m.e10, 
         names=c("5000", "500", "100", "50", "10"), range=0,
         main="Exp(1/5), Sample mean",
         horizontal=T )
dev.off()

pdf(file="z_hist_mean_exp_.pdf", width=7.0, height=9.0)
par(mfrow=c(5,1), mai=c(0.3, 0.3, 0.6, 0.1), cex.main=1.0  )
hist(m.e10  , main="Exp(1/5), Sample mean, n=10"  , xlim=c(1,12), probability=F, ylab="")
hist(m.e50  , main="Exp(1/5), Sample mean, n=50"  , xlim=c(1,12), probability=F, ylab="")
hist(m.e100 , main="Exp(1/5), Sample mean, n=100" , xlim=c(1,12), probability=F, ylab="")
hist(m.e500 , main="Exp(1/5), Sample mean, n=500" , xlim=c(1,12), probability=F, ylab="")
hist(m.e5000, main="Exp(1/5), Sample mean, n=5000", xlim=c(1,12), probability=F, ylab="")
dev.off()

pdf(file="z_qq_mean_exp_.pdf", width=4.0, height=17.0)
par(mfrow=c(5,1), mai=c(0.6, 0.6, 0.6, 0.1)  )
qqnorm(m.e10  , main="Exp(1/5), Sample mean, n=10"  ); qqline(m.e10  )
qqnorm(m.e50  , main="Exp(1/5), Sample mean, n=50"  ); qqline(m.e50  )
qqnorm(m.e100 , main="Exp(1/5), Sample mean, n=100" ); qqline(m.e100 )
qqnorm(m.e500 , main="Exp(1/5), Sample mean, n=500" ); qqline(m.e500 )
qqnorm(m.e5000, main="Exp(1/5), Sample mean, n=5000"); qqline(m.e5000)
dev.off()


###
# zad42
Nrep <- 10000
sim.exp <- function(n, lambda, alpha) {
  x <- rexp(n, lambda)
  x.bar <- mean(x)
  s <- sd(x)
  ci1 <- x.bar - qnorm(1-alpha/2)*(s/sqrt(n))
  ci2 <- x.bar + qnorm(1-alpha/2)*(s/sqrt(n))
  c(ci1, ci2) 
}

rs1 <- replicate( Nrep, sim.exp(50, 1/5, 0.05) )
sum( rs1[1,] < 5 & rs1[2,] > 5 )/Nrep


###
# zad43
Nrep <- 7000

u10   <- replicate( Nrep, runif(10  , 2, 8) )
u50   <- replicate( Nrep, runif(50  , 2, 8) )
u100  <- replicate( Nrep, runif(100 , 2, 8) )
u500  <- replicate( Nrep, runif(500 , 2, 8) )
u5000 <- replicate( Nrep, runif(5000, 2, 8) )

m.u10   <- apply(u10  , 2, mean)
m.u50   <- apply(u50  , 2, mean)
m.u100  <- apply(u100 , 2, mean)
m.u500  <- apply(u500 , 2, mean)
m.u5000 <- apply(u5000, 2, mean)

pdf(file="z_boxplot_mean_unif_.pdf", width=7.0, height=4.5)
par(mai=c(0.5, 0.5, 0.5, 0.1))
boxplot( m.u5000, m.u500, m.u100, m.u50, m.u10, 
         names=c("5000", "500", "100", "50", "10"), range=0,
         main="U(2,8), Sample mean",
         horizontal=T )
dev.off()

pdf(file="z_hist_mean1_unif_.pdf", width=7.0, height=9.0)
par(mfrow=c(5,1), mai=c(0.3, 0.3, 0.6, 0.1), cex.main=1.0  )
hist(m.u10  , main="U(2,8), Sample mean, n=10"  , xlim=c(2,8), probability=F, ylab="")
hist(m.u50  , main="U(2,8), Sample mean, n=50"  , xlim=c(2,8), probability=F, ylab="")
hist(m.u100 , main="U(2,8), Sample mean, n=100" , xlim=c(2,8), probability=F, ylab="")
hist(m.u500 , main="U(2,8), Sample mean, n=500" , xlim=c(2,8), probability=F, ylab="")
hist(m.u5000, main="U(2,8), Sample mean, n=5000", xlim=c(2,8), probability=F, ylab="")
dev.off()

pdf(file="z_qq_mean1_unif_.pdf", width=4.0, height=17.0)
par(mfrow=c(5,1), mai=c(0.6, 0.6, 0.6, 0.1)  )
qqnorm(m.u10  , main="U(2,8), Sample mean, n=10"  ); qqline(m.u10  )
qqnorm(m.u50  , main="U(2,8), Sample mean, n=50"  ); qqline(m.u50  )
qqnorm(m.u100 , main="U(2,8), Sample mean, n=100" ); qqline(m.u100 )
qqnorm(m.u500 , main="U(2,8), Sample mean, n=500" ); qqline(m.u500 )
qqnorm(m.u5000, main="U(2,8), Sample mean, n=5000"); qqline(m.u5000)
dev.off()


###
# zad44
Nrep <- 10000
sim.unif <- function(n, a, b, alpha) {
  x <- runif(n, a, b)
  x.bar <- mean(x)
  s <- sd(x)
  ci1 <- x.bar - qnorm(1-alpha/2)*(s/sqrt(n))
  ci2 <- x.bar + qnorm(1-alpha/2)*(s/sqrt(n))
  c(ci1, ci2) 
}

rs2 <- replicate( Nrep, sim.unif(50, 2, 8, 0.05) )
sum( rs2[1,] < 5 & rs2[2,] > 5 )/Nrep


###
# zad45
z1.ci <- function(x.bar, sigma, n, alpha) {
  b1 <- x.bar - qnorm(1-alpha/2)*(sigma/sqrt(n))
  b2 <- x.bar + qnorm(1-alpha/2)*(sigma/sqrt(n))
  c(b1, b2)
}

z1.ci( x.bar=2100, sigma=300, n=100, alpha=0.05 )
z1.ci( x.bar=2100, sigma=300, n=200, alpha=0.05 )


###
# zad46
t1.ci <- function(x.bar, s, n, alpha) {
  b1 <- x.bar - qt(1-alpha/2, df=n-1)*(s/sqrt(n))
  b2 <- x.bar + qt(1-alpha/2, df=n-1)*(s/sqrt(n))
  c(b1, b2)
}

x <- c(6.1, 5.4, 4.8, 5.8, 6.6, 5.3, 6.1, 4.4, 3.9, 6.8, 6.5, 6.3)

t1.ci( x.bar=mean(x), s=sd(x), n=length(x), alpha=0.05 )
t1.ci( x.bar=mean(x), s=sd(x), n=length(x), alpha=0.01 )

t.test( x, conf.level=0.95 )$conf.int[1:2]
t.test( x, conf.level=0.99 )$conf.int[1:2]


###
# zad47
prop1.ci <- function(x, n, alpha) {
  p.hat <- x/n
  b1 <- p.hat - qnorm(1-alpha/2)*sqrt(p.hat*(1-p.hat)/n)
  b2 <- p.hat + qnorm(1-alpha/2)*sqrt(p.hat*(1-p.hat)/n)
  c(b1, b2)
}

prop1.ci( x=2700, n=25000, alpha=0.05 )

prop.test( x=2700, n=25000, conf.level=0.95, correct=F )$conf.int[1:2]


###
# zad48
salk <- read.table("salk.txt")
hist(salk[,1])
hist(salk[,2])
summary(salk)


med1.ci <- function(x, alpha=0.05, nboot=1000) {
  x <- x[is.finite(x)]
  nx <- length(x)
  est1 <- median(x)
  med1.bt <- replicate( nboot, median( sample( x, size=nx, replace=TRUE ) ) )
  ci <- quantile( med1.bt, probs=c(alpha/2, 1-alpha/2), names=FALSE )
  list( est.med1=est1, ci=ci )
}

med1.ci( salk[,1], alpha=0.05, nboot=10000 )
med1.ci( salk[,2], alpha=0.05, nboot=10000 )


###
# zad49
med2.ci <- function(x, y, alpha=0.05, nboot=1000) {
  x <- x[is.finite(x)]
  y <- y[is.finite(y)]
  nx <- length(x)
  ny <- length(y)
  est1 <- median(x)
  est2 <- median(y)
  est.dif <- est1 - est2
  
  med1.bt <- replicate( nboot, median( sample( x, size=nx, replace=TRUE ) ) )
  med2.bt <- replicate( nboot, median( sample( y, size=ny, replace=TRUE ) ) )
  
  dif.bt <- med1.bt - med2.bt
  
  ci <- quantile( dif.bt, probs=c(alpha/2, 1-alpha/2), names=FALSE )
  
  list( est.med1=est1, est.med2=est2, est.dif=est.dif, ci=ci )
}

med2.ci( salk[,1], salk[,2], alpha=0.05, nboot=10000 )


###
# zad50
# mu = средно време на живот на новия тип крушки
# H0: mu = 2000
# H1: mu > 2000

x.bar <- 2100
n <- 100
sigma <- 300
mu <- 2000
z.obs <- (x.bar - mu) / (sigma/sqrt(n))
z.obs
p.value <- 1-pnorm(z.obs)
p.value

# p.value < 0.05 => отхвърляме нулевата хипотеза. 
# Имаме основания да твърдим, че средното време на живот на 
# новия тип крушки е повече от 2000 часа.


###
# zad51
# mu = средна киселинност на дъждовете в района за изминалата година
# H0: mu = 5.2
# H1: mu != 5.2

x <- c(6.1, 5.4, 4.8, 5.8, 6.6, 5.3, 6.1, 4.4, 3.9, 6.8, 6.5, 6.3)
n <- length(x)
mu <- 5.2
t.obs <- (mean(x) - mu) / (sd(x)/sqrt(n))
t.obs
p.value <- 2*(1-pt(abs(t.obs), n-1))
p.value

# p.value > 0.05 
# => Нямаме достатъчно основания да отхвърлим нулевата хипотеза.
# Нямаме основания да твърдим, че средната киселинност в района 
# се е променила в сравнение с историческите данни.

t.test(x, mu=5.2)
t.test(x, mu=5.2)$p.value


###
# zad52
# p = вероятността кола от новия модел да е дефектна
# H0: p = 0.1
# H1: p != 0.1

x <- 2700
n <- 25000
p <- 0.1
z.obs <- ((x/n) - p) / sqrt(p*(1-p)/n)
z.obs
p.value <- 2*(1-pnorm(abs(z.obs)))
p.value

# p.value < 0.05 => отхвърляме нулевата хипотеза.
# Имаме основания да твърдим, че процентът на дефектните коли 
# от новия модел ще е различен от 10%.

prop.test(x=2700, n=25000, p=0.1, correct=F)
prop.test(x=2700, n=25000, p=0.1, correct=F)$p.value


###
# zad53
# p = вероятността новото лекарство да е ефективно
# H0: p = 0.72
# H1: p > 0.72

x <- 42
n <- 50
p <- 0.72
z.obs <- ((x/n) - p) / sqrt(p*(1-p)/n)
z.obs
p.value <- 1-pnorm(z.obs)
p.value

# p.value < 0.05 => отxвърляме нулевата хипотеза.
# Имаме основание да твърдим, че новото лекарство ще е 
# ефективно в повече от 72% от случаите.

prop.test(x=42, n=50, p=0.72, alt="greater", correct=F)
prop.test(x=42, n=50, p=0.72, alt="greater", correct=F)$p.value


###
# zad54a
# p = вероятността стока да има грешна цена
# H0: p = 0.075
# H1: p != 0.075

prop.test(x=14, n=200, p=0.075, correct=F)
prop.test(x=14, n=200, p=0.075, correct=F)$p.value

# p.value > 0.05 => нямаме основания да отхвърлим нулевата хипотеза.
# Нямаме основания да твърдим, че процентът на стоки с 
# грешна цена се е променил спрямо 2009 година.


###
# zad54b
# p = вероятността стока да има грешна цена
# H0: p = 0.075
# H1: p < 0.075

prop.test(x=14, n=200, p=0.075, alt="less", correct=F)
prop.test(x=14, n=200, p=0.075, alt="less", correct=F)$p.value

# p.value > 0.05 => нямаме основания да отхвърлим нулевата хипотеза.
# Нямаме основания да твърдим, че процентът на стоки с 
# грешна цена е намалял спрямо 2009 година.


###
# zad55
# mu  = средно количество течност, което налива автоматът
# H0: mu = 170
# H0: mu < 170

x.bar <- 168
n <- 50
sigma <- 3.9
mu <- 170
z.obs <- (x.bar - mu) / (sigma/sqrt(n))
z.obs
p.value <- pnorm(z.obs)
p.value

# p.value < 0.05 => отxвърляме нулевата хипотеза.
# Имаме основания да твърдим, че в средно
# автоматът налива по-малко от 170 грама.


###
# zad56a
# mu = средно ниво на хемоглобин при децата страдащи от тази болест
# H0: mu = 14.6
# H1: mu != 14.6

x <- c(12.3, 11.4, 14.2, 15.3, 14.8, 13.8, 11.1, 15.1, 15.8, 13.2)

t.test(x, mu=14.6)

# p.value > 0.05 => нямаме основания да отхвърлим нулевата хипотеза.
# Нямаме основания да твърдим, че средното ниво на хемоглобин при децата 
# страдащи от тази болест е различно от нормалното ниво от 14.6.


###
# zad56b
# mu = средно ниво на хемоглобин при децата страдащи от тази болест
# H0: mu = 14.6
# H1: mu < 14.6

t.test(x, mu=14.6, alt="less")

# p.value > 0.05 => нямаме основания да отхвърлим нулевата хипотеза.
# Нямаме основания да твърдим, че средното ниво на хемоглобин при децата 
# страдащи от тази болест е по-малко от нормалното ниво от 14.6.



###
# zad57
# muX = среден брой грешки на работилите с допълнителна почивка
# muY = среден брой грешки на работилите без допълнителна почивка
# H0: muX = muY
# H1: muX < muY

x <- c(8, 7, 5, 8, 10, 9, 7, 8, 4, 5)
y <- c(7, 6, 14, 12, 13, 8, 9, 6, 10, 9)
n <- length(x)
m <- length(y)
t.obs <- (mean(x) - mean(y)) / sqrt(var(x)/n + var(y)/m)
t.obs
df <- (var(x)/n + var(y)/m)^2 / (((var(x)/n)^2)/(n-1) + ((var(y)/m)^2)/(m-1))
df
p.value <- pt(t.obs, df)
p.value
t.test(x, y, alt="less")

# p.value < 0.05 => отхвърляме нулевата хипотеза.
# Имаме основание да твърдим, че работниците с 
# допълнителна почивка правят средно по-малко грешки.


###
# zad58
# muX = средно ниво на холестерол преди диетата
# muY = средно ниво на холестерол след диетата
# H0: muX = muY
# H1: muX > muY

# x <- c(265,240,258,295,251,245,287,314,260,279,283,240,238,225,247)
# y <- c(229,231,227,240,238,241,234,256,247,239,246,218,219,226,233)

zad58 <- read.table("zad58.txt")
x <- zad58[,2]
y <- zad58[,3]

d <- x - y
n <- length(x)
t.obs <- mean(d) / (sd(d)/sqrt(n))
t.obs
p.value <- 1-pt(t.obs, n-1)
p.value
t.test(x, y, alt="greater", paired=T)
t.test(x-y, alt="greater")

# p.value < 0.05 => отхвърляме нулевата хипотеза.
# Може да се твърди, че диетата намалява 
# нивото на холестерол в средно.


###
# zad59
# p1 е вероятността ваксиниран пациент да се разболее
# p2 е вероятността третиран с плацебо пациент да се разболее
# H0: p1 = p2
# H1: p1 < p2

# x1 = 29, n1 =102
# x2 = 34, n2 =102

x <- c(29,34)
n <- c(102,102)
p.hat <- (x[1] + x[2]) / (n[1] + n[2])
z.obs <- (x[1]/n[1] - x[2]/n[2]) / sqrt(p.hat*(1-p.hat)*(1/n[1] + 1/n[2]))
z.obs
p.value <- pnorm(z.obs)
p.value
prop.test(x, n, alt="less", correct=F)

# p.value > 0.05 => нямаме основания да отхвърлим нулевата хипотеза.
# Нямаме достатъчно основания да твърдим, че ваксината е ефективна.


###
# zad60
# muX = средно време за четене при първия шрифт
# muY = средно време за четене при втория шрифт
# H0: muX = muY
# H1: muX != muY

x.bar <- 7.88
y.bar <- 8.48
s.x <- 1.73
s.y <- 2.12
n <- 50
m <- 50
t.obs <- (x.bar - y.bar) / sqrt(s.x^2/n + s.y^2/m)
t.obs
df <- (s.x^2/n + s.y^2/m)^2 / (((s.x^2/n)^2)/(n-1) + ((s.y^2/m)^2)/(m-1))
df
p.value <- 2*(1-pt(abs(t.obs), df))
p.value

# p.value with pnorm()
p.value2 <- 2*(1-pnorm(abs(t.obs)))
p.value2

# p.value > 0.05 => нямаме основания да отхвърлим нулевата хипотеза.
# Нямаме основания да твърдим, че средното време за четене 
# е различно за двата шрифта


###
# zad61
# muX = средно съдържание на примеси при определяне по първия метод 
# muY = средно съдържание на примеси при определяне по втория метод
# H0: muX = muY
# H1: muX != muY

zad61 <- read.table("zad61.txt")
x <- zad61[,2]
y <- zad61[,3]
t.test(x, y, paired=T)

# p.value < 0.05 => отхвърляме нулевата хипотеза.
# Не може да се приеме, че двата метода дават в средно 
# едни и същи резултати.


###
# zad63
sim1 <- function(n, alpha) {
  x <- runif(n, 5, 9)
  ci <- t.test(x, conf.level=1-alpha)$conf.int[1:2]
  cnd1 <- ( ci[1] <= 7 & ci[2] >= 7 )
  cnd1
}

rs1 <- replicate( 10000, sim1(n=500, alpha=0.05) )
table(rs1)/length(rs1)


###
# zad64
sim2 <- function(n, alpha) {
  x <- runif(n, 5, 9)
  p.val <- t.test(x, mu=7)$p.value
  cnd2 <- ( p.val > alpha )
  cnd2
}

rs2 <- replicate( 10000, sim2(n=500, alpha=0.05) )
table(rs2)/length(rs2)


###
# zad65
sim3 <- function(n, alpha) {
  x <- runif(n, 5, 9)
  ci <- t.test(x, conf.level=1-alpha)$conf.int[1:2]
  p.val <- t.test(x, mu=7)$p.value
  cnd1 <- ( ci[1] <= 7 & ci[2] >= 7 )
  cnd2 <- ( p.val > alpha )
  # cnd1 == cnd2
  c( cnd1, cnd2 )
}

rs3 <- replicate( 10000, sim3(n=500, alpha=0.05) )
cnd1r <- rs3[1, ]
cnd2r <- rs3[2, ]
table(cnd1r, cnd2r)


###
# zad66
sim4 <- function(n, mu, delta) {
  x <- rnorm(n, mean=mu, sd=1)
  y <- rnorm(n, mean=mu+delta, sd=1)
  t.test(x,y)$p.value
}

rs4 <- replicate( 10000, sim4(n=1000, mu=5, delta=0.2) )
sum(rs4<=0.05)/length(rs4)


###
# zad67
# p_i = вероятността да се падне i, i=1...6
# H0: p_i = 1/6, i=1...6
# H1: p_i != 1/6 за поне едно i

x <- c(28, 36, 36, 30, 27, 23)
probs <- rep(1/6, 6)

n <- sum(x)
k <- length(probs)
chi2.obs <- sum( (x - n*probs)^2 / (n*probs) )
chi2.obs
p.value <- 1-pchisq(chi2.obs, df=k-1)
p.value

chisq.test(x, p=probs)
chisq.test(x, p=probs)$p.value

# p.value > 0.05 => нямаме основания да охвърлим H0.
# Можем да считаме, че зарът е правилен 
# (всяка от страните се пада с вероятност 1/6).

tb1 <- rbind( probs, x/sum(x) )
colnames(tb1) <- as.character(c(1:6))
rownames(tb1) <- c("probability (H0)", "observed freq")
barplot(tb1, beside=T, legend=T, ylim=c(0,0.25))


###
# zad68
# p_1 = вероятността да цъфти в бяло
# p_2 = вероятността да цъфти в розово
# p_3 = вероятността да цъфти в червено
# H0: (p_1, p_2, p_3) = (1/4, 1/2, 1/4)
# H1: (p_1, p_2, p_3) != (1/4, 1/2, 1/4)

x <- c(141, 291, 132)
probs <- c(1/4, 1/2, 1/4)

n <- sum(x)
k <- length(probs)
chi2.obs <- sum( (x - n*probs)^2 / (n*probs) )
chi2.obs
p.value <- 1-pchisq(chi2.obs, df=k-1)
p.value

chisq.test(x, p=probs)

# p.value > 0.05 => нямаме основания да охвърлим H0.
# Резултатите са в съгласие с теорията на Мендел.

tb1 <- rbind( probs, x/sum(x) )
colnames(tb1) <- c("white", "pink", "red")
rownames(tb1) <- c("probability (H0)", "observed freq")
barplot(tb1, beside=T, legend=T, args.legend=list(x="topright"))


###
# zad69
# p_E = вероятността да срещнем буква Е
# p_T = вероятността да срещнем буква T
# ...
# H0: (p_E, p_T, ...) = (0.1202, 0.0910, ...)
# H1: (p_E, p_T, ...) != (0.1202, 0.0910, ...)

load("letterFreq.RData")
probs*100
x1

chisq.test(x1, p=probs)

# p.value < 0.05 => отхвърляме H0.
# Нямаме основания да твърдим, че вероятностите за срещане 
# на съответните букви са както в английския език.

tb1 <- rbind( probs, x1/sum(x1) )
rownames(tb1) <- c("probability (H0)", "observed freq")
barplot(tb1, beside=T, legend=T, args.legend=list(x="top"))


###
# zad71
library(MASS)
tb <- table( survey$Sex, survey$Smoke )
tb

# H0: пушенето и пола са независими
# H1: пушенето и пола не са независими (има връзка между пушене и пол)

n <- sum(tb)
df <- (nrow(tb)-1)*(ncol(tb)-1)
sex <- apply(tb, 1, sum)
smk <- apply(tb, 2, sum)

expected <- (sex %o% smk)/n
observed <- tb
chi2.obs <- sum( (observed - expected)^2 / expected )
chi2.obs
p.value <- 1-pchisq(chi2.obs, df)
p.value

chisq.test(tb)

# p.value > 0.05 
# => нямаме основания да отхвърлим нулевата хипотеза.
# Нямаме основания да твърдим, че има връзка между пушенето и пола.

observed
chisq.test(tb)$observed
expected
chisq.test(tb)$expected


###
# zad72
data(HairEyeColor)
tb <- HairEyeColor[,,1] + HairEyeColor[,,2]
tb

# H0: цвета на косата и цвета на очите са независими
# H1: има връзка между цвета на косата и цвета на очите

n <- sum(tb)
df <- (nrow(tb)-1)*(ncol(tb)-1)
hair <- apply(tb, 1, sum)
eyes <- apply(tb, 2, sum)

expected <- (hair %o% eyes)/n
observed <- tb
chi2.obs <- sum( (observed - expected)^2 / expected )
chi2.obs
p.value <- 1-pchisq(chi2.obs, df)
p.value

chisq.test(tb)$p.value

# p.value < 0.05 
# => отхвръляме нулевата хипотеза.
# Можем да твърдим, че има връзка между
# цвета на косата и цвета на очите.

observed
chisq.test(tb)$observed
expected
chisq.test(tb)$expected


###
# zad74
alco <- read.table("bac.txt", header=T)

# а)
m1 <- lm( bac ~ beers, data=alco )
m1
# y = съдържание на алкохол в кръвта (bac)
# x = брой изпити бири (beers)
# модел:
# y = beta0 + beta1*x + eps
# оценено регресионно уравнение:
# y.hat = -0.01270 + 0.01796*x

plot( bac ~ beers, data=alco )
abline( coef(m1), lwd=2 )

# графика на остатъците срещу y.hat
plot( fitted(m1), resid(m1) )

# б)
# При изпиване на още една бира съдържанието на алк. в кръвта
# се увеличава средно с 0.01796.
# При нула изпити бири средното съдържание на алк. в кръвта 
# е -0.01270.

# в)
# H0: beta1 = 0
# H1: beta1 != 0
summary(m1)
summary(m1)$coefficients
p.value <- summary(m1)$coefficients[2,4]
p.value < 0.05
# => отхвърляме H0.
# Можем да твърдим, че има линейна връзка между броя на изпитите
# бири и съдържанието на алкохол в кръвта.

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
# zad75
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
# успех от първата година по-висок средно с 0.74314.

# H0: beta1 = 0
# H1: beta1 != 0
summary(m1)
p.value <- summary(m1)$coefficients[2,4]
p.value < 0.05 
# => отхвърляме H0.
# Можем да твърдим, че има линейна връзка между
# двете променливи.

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

cor(satgpa$sat_sum, satgpa$sat_m)

summary(m1)$adj.r.squared
summary(m2)$adj.r.squared
summary(m3)$adj.r.squared
# Моделът m2 има най-голям adj.r.squared => е най-добър от трите.


###
# zad76
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

# sum( coef(m3)*c(1, 14^2, 70) )

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
# zad77
duke <- read.csv("duke_forest.csv", header=T)
pairs( duke[,c(2,3,4,5,7,11)], gap=0, cex.labels=0.9 )
m1 <- lm( price ~ bed + area + lot, data=duke )
summary(m1)

m2 <- lm( price ~ area + lot, data=duke )
summary(m2)

m3 <- lm( price ~ bed + lot, data=duke )
summary(m3)

m4 <- lm( price ~ area + lot + year_built, data=duke )
summary(m4)
plot( fitted(m4), resid(m4) )

which.min(resid(m4))
which.min(duke$price)
min(duke$price)

m5 <- lm( price ~ area + lot + year_built, data=duke, subset=(price>95000) )
summary(m5)
plot( fitted(m5), resid(m5) )

cor(duke$bed, duke$bath)
cor(duke$bed, duke$area)
cor(duke$bed, duke$lot, use="complete.obs")
cor(duke$lot, duke$area, use="complete.obs")
cor( duke[,c(2,3,4,5,7,11)], use="complete.obs")

###########################################################

