P1 = .15;
P2 = 0;

w = sqrt(3456*P1);
zeta = (64.8*P2 + 5)/(2*w)
w
Mp = exp((-pi*zeta)/(sqrt(1-zeta^2)));
Mp = Mp*100

if(zeta > 0 && zeta < 1.2)
    tr = (1.2 - 0.45*zeta + 2.6*(zeta^2))/(w)
else
    tr = (4.7*zeta - 1.2)/w;
end

if(zeta > 0 && zeta <= 0.69)
    ts = (-0.5/(zeta*w))*log((1-zeta^2)/400)
else
    ts = (6.6*zeta - 1.6)/w
end

error = 1/w^2

