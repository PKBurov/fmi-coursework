## hypotheses 2 samples
##
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


##
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

2*(1-pnorm(abs(t.obs)))


##
x <- c(265,240,258,295,251,245,287,314,260,279,283,240,238,225,247)
y <- c(229,231,227,240,238,241,234,256,247,239,246,218,219,226,233)
d <- x - y
n <- length(x)
t.obs <- mean(d) / (sd(d)/sqrt(n))
t.obs
p.value <- 1-pt(t.obs, n-1)
p.value
t.test(x, y, alt="greater", paired=T)


##
zadSteel <- read.table("zadSteel.txt")
x <- zadSteel[,2]
y <- zadSteel[,3]
t.test(x, y, paired=T)


##
x <- c(29,34)
n <- c(102,102)
p.hat <- (x[1] + x[2]) / (n[1] + n[2])
z.obs <- (x[1]/n[1] - x[2]/n[2]) / sqrt(p.hat*(1-p.hat)*(1/n[1] + 1/n[2]))
z.obs
p.value <- pnorm(z.obs)
p.value
prop.test(x, n, alt="less", correct=F)


##
x <- c(71,58)
n <- c(220,210)
p.hat <- (x[1] + x[2]) / (n[1] + n[2])
z.obs <- (x[1]/n[1] - x[2]/n[2]) / sqrt(p.hat*(1-p.hat)*(1/n[1] + 1/n[2]))
z.obs
p.value <- 2*(1-pnorm(abs(z.obs)))
p.value
prop.test(x, n, correct=F)

