###
library(MASS)
tb <- table( survey$Sex, survey$Smoke )
tb
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

observed
chisq.test(tb)$observed
expected
chisq.test(tb)$expected


###
data(HairEyeColor)
tb <- HairEyeColor[,,1] + HairEyeColor[,,2]
tb
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

chisq.test(tb)

observed
chisq.test(tb)$observed
expected
chisq.test(tb)$expected



###
# set.seed(12); beta1=1.5; sigma=2
# set.seed(12); beta1=1.5; sigma=1
# set.seed(12); beta1=0.5; sigma=1

set.seed(12)
n <- 50
beta0 <- 2
beta1 <- 1.5
sigma <- 2
x <- runif(n, 1, 7)
y <- beta0 + beta1*x + rnorm(n, 0, sigma)
m1 <- lm(y~x)
summary(m1)
summary(m1)$coefficients
summary(m1)$r.squared
coef(m1)
confint(m1)
confint(m1, "x")
plot( fitted(m1), resid(m1) )

plot(x, y)
abline( coef(m1), lwd=2 )
abline( a=beta0, b=beta1, col="red", lwd=2 )

xx <- data.frame(x=seq(1, 7, 0.05))
cint <- predict( m1, xx, interval="confidence" )
pint <- predict( m1, xx, interval="prediction" )

lines( xx$x, cint[,2], type="l", lty="dotted", lwd=2 )
lines( xx$x, cint[,3], type="l", lty="dotted", lwd=2 )

lines( xx$x, pint[,2], type="l", lty="dotted", col="gray", lwd=2 )
lines( xx$x, pint[,3], type="l", lty="dotted", col="gray", lwd=2 )


