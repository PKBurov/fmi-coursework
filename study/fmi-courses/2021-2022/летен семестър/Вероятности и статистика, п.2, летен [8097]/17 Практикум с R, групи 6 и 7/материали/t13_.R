
##
alco <- read.table("bac.txt", header=T)
m1 <- lm( bac ~ beers, data=alco )

plot( bac ~ beers, data=alco )
abline( coef(m1), lwd=2 )
summary(m1)
confint(m1)
plot( fitted(m1), resid(m1) )

predict( m1, data.frame( beers=c(5) ), interval="confidence" )

xx <- data.frame( beers=seq(1, 9, 0.5) )
cint <- predict( m1, xx, interval="confidence" )
lines( xx$beers, cint[,2], type="l", lty="dotted", lwd=2 )
lines( xx$beers, cint[,3], type="l", lty="dotted", lwd=2 )

pint <- predict( m1, xx, interval="prediction" )
lines( xx$beers, pint[,2], type="l", lty="dotted", col="gray", lwd=2 )
lines( xx$beers, pint[,3], type="l", lty="dotted", col="gray", lwd=2 )


##
satgpa <- read.table("satgpa.txt", header=T)
pairs( satgpa, gap=0, cex.labels=0.9 )
m1 <- lm( fy_gpa ~ hs_gpa, data=satgpa )

plot( fy_gpa ~ hs_gpa, data=satgpa )
abline( coef(m1), lwd=2 )

summary(m1)
confint(m1)
plot( fitted(m1), resid(m1) )

predict( m1, data.frame( hs_gpa=3.5 ), interval="confidence" )
predict( m1, data.frame( hs_gpa=3.5 ), interval="prediction" )

m2 <- lm( fy_gpa ~ hs_gpa + sat_sum, data=satgpa )
summary(m2)
confint(m2)
plot( fitted(m2), resid(m2) )

m3 <- lm( fy_gpa ~ hs_gpa + sat_m, data=satgpa )
summary(m3)
confint(m3)
plot( fitted(m3), resid(m3) )


##
cher <- read.table("cherry.txt", header=T)
pairs( cher, gap=0, cex.labels=0.9 )

m1 <- lm( volume ~ diam, data=cher )

plot( volume ~ diam, data=cher )
abline( coef(m1), lwd=2 )

summary(m1)
confint(m1)
plot( fitted(m1), resid(m1) )

m2 <- lm( volume ~ diam + height, data=cher )
summary(m2)
confint(m2)
plot( fitted(m2), resid(m2) )

ci1470.1 <- predict( m2, data.frame( diam=14, height=70 ), interval="confidence" )
ci1470.1

cher$diam2 <- cher$diam^2
m3 <- lm( volume ~ diam2 + height, data=cher )
summary(m3)
confint(m3)
plot( fitted(m3), resid(m3) )

sum( coef(m3)*c(1, 14^2, 70) )

ci1470.2 <- predict( m3, data.frame( diam2=14^2, height=70 ), interval="confidence" )
ci1470.2

ci1470.1[3] - ci1470.1[2]
ci1470.2[3] - ci1470.2[2]

m4 <- lm( volume ~ I(diam^2) + height, data=cher )
predict( m4, data.frame( diam=14, height=70 ), interval="confidence" )


##
duke <- read.csv("duke_forest.csv", header=T)
pairs( duke[,c(2,3,4,5,11)], gap=0, cex.labels=0.9 )
m1 <- lm( price ~ bed + area + lot, data=duke )
summary(m1)

m2 <- lm( price ~ area + lot, data=duke )
summary(m2)

m3 <- lm( price ~ bed + lot, data=duke )
summary(m3)

m4 <- lm( price ~ area + lot + year_built, data=duke )
summary(m4)
summary(m4)$adj.r.squared	
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



