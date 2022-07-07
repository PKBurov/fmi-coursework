### RNG 

x <- runif(5000, 0, 1)
lambda <- 1/8
y <- -(1/lambda)*log(1-x)
hist(y, probability=T, breaks="Scott")
curve( dexp(x, lambda), from=0, to=max(y), add=T, lwd=2 )


a <- 10000000
b <- 2*a
x <- sample( c(a:b), 5000, replace=T )
y <- (x-a)/(b-a)
hist(y)
summary(y)
y[1:10]


set.seed(101)
runif(5)
sample( c(1:100), 5, replace=T )


###
Nrep <- 3000

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
Nrep <- 10000
sim.exp <- function(n, lambda, alpha) {
  x <- rexp(n, lambda)
  x.bar <- mean(x)
  s <- sd(x)
  ci1 <- x.bar - qnorm(1-alpha/2)*(s/sqrt(n))
  ci2 <- x.bar + qnorm(1-alpha/2)*(s/sqrt(n))
  c(ci1, ci2) 
}

rs1 <- replicate( Nrep, sim.exp(10, 1/5, 0.05) )
sum( rs1[1,] < 5 & rs1[2,] > 5 )/Nrep

