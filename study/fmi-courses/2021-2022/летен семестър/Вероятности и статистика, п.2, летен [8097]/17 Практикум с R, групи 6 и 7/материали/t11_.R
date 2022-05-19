
##
sim1 <- function(n, alpha) {
  x <- runif(n, 5, 9)
  ci <- t.test(x, conf.level=1-alpha)$conf.int[1:2]
  cnd1 <- ( ci[1] <= 7 & ci[2] >= 7 )
  cnd1
}

rs1 <- replicate( 10000, sim1(n=20, alpha=0.05) )
table(rs1)/length(rs1)


##
sim2 <- function(n, alpha) {
  x <- runif(n, 5, 9)
  p.val <- t.test(x, mu=7)$p.value
  cnd2 <- ( p.val >= alpha )
  cnd2
}

rs2 <- replicate( 10000, sim2(n=20, alpha=0.05) )
table(rs2)/length(rs2)


##
sim3 <- function(n, alpha) {
  x <- runif(n, 5, 9)
  ci <- t.test(x, conf.level=1-alpha)$conf.int[1:2]
  p.val <- t.test(x, mu=7)$p.value
  cnd1 <- ( ci[1] <= 7 & ci[2] >= 7 )
  cnd2 <- ( p.val >= alpha )
  cnd1 == cnd2
}

rs3 <- replicate( 10000, sim3(n=20, alpha=0.05) )
table(rs3)


##
sim4 <- function(n, mu, delta) {
  x <- rnorm(n, mean=mu, sd=1)
  y <- rnorm(n, mean=mu+delta, sd=1)
  t.test(x,y)$p.value
}

rs4 <- replicate( 1000, sim4(n=100, mu=5, delta=0.2) )
sum(rs4<0.05)/length(rs4)



##
# dice
x <- c(28, 36, 36, 30, 27, 23)
probs <- rep(1/6, 6)
chisq.test(x, p=probs)

n <- sum(x)
k <- length(probs)
chi2.obs <- sum( (x - n*probs)^2 / (n*probs) )
chi2.obs
p.value <- 1-pchisq(chi2.obs, df=k-1)
p.value

tb1 <- rbind( probs, x/sum(x) )
colnames(tb1) <- as.character(c(1:6))
rownames(tb1) <- c("probability (H0)", "observed freq")
barplot(tb1, beside=T, legend=T, ylim=c(0,0.25))


##
# peas
x <- c(141, 291, 132)
probs <- c(1/4, 1/2, 1/4)
chisq.test(x, p=probs)

n <- sum(x)
k <- length(probs)
chi2.obs <- sum( (x - n*probs)^2 / (n*probs) )
chi2.obs
p.value <- 1-pchisq(chi2.obs, df=k-1)
p.value

tb1 <- rbind( probs, x/sum(x) )
colnames(tb1) <- c("white", "pink", "red")
rownames(tb1) <- c("probability (H0)", "observed freq")
barplot(tb1, beside=T, legend=T, args.legend=list(x="topright"))


##
load("letterFreq.RData")
probs*100
x1

chisq.test(x1, p=probs)

tb1 <- rbind( probs, x1/sum(x1) )
rownames(tb1) <- c("probability (H0)", "observed freq")
barplot(tb1, beside=T, legend=T, args.legend=list(x="top"))

##

