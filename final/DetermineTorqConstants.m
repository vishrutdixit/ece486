%% idea:  use a coeff fit to get nice derivatives
% This function takes a cubic fit of the initial data for both 
% Theta_p and Theta_r.  Having a cubic fit is better than 
% trying to take the derivative of noisy data for many reasons.
% The function easily computes the first and second derivatives. 
%    
% It does requires you to do two things:
% 
% 1.) enter your u, a (=omega_np^2), b, and c
% 2.) Come up with the equation for br and bp
function [bpMax, brMax] = DetermineTorqConstants(plot_time, Theta_p,Theta_r)
%% plot the data

[s,i] = min(Theta_p) % we only want the data from zero to the first minimum
indexes = 1:i;
plot(plot_time(indexes),Theta_p(indexes))

close all
t = plot_time(indexes);
%first get a fit for the theta_p data ('D' stands for 1st derivative,
%'DD' for second derivative)
coeffs = polyfit(plot_time(indexes),Theta_p(indexes),3);
p = coeffs(1).*t.^3+coeffs(2).*t.^2+coeffs(3).*t.^1+coeffs(4).*t.^0;
pD = 3*coeffs(1).*t.^2+2*coeffs(2).*t.^1+coeffs(3).*t.^0;
pDD =  6*coeffs(1).*t.^1+2*coeffs(2).*t.^0;
%next get fir
coeffs = polyfit(plot_time(indexes),Theta_r(indexes),3);
r = coeffs(1).*t.^3+coeffs(2).*t.^2+coeffs(3).*t.^1+coeffs(4).*t.^0;
rD = 3*coeffs(1).*t.^2+2*coeffs(2).*t.^1+coeffs(3).*t.^0;
rDD = 6*coeffs(1).*t.^1+2*coeffs(2).*t.^0;

%% 1.) Put your values here:
u = 5;
a = 77.64;% a = (omega_np^2)
b = .0126;
c = .605;

%% 2.) actually find the bp and br values
% You need to fill this in yourself.  Use the variables p, pD,pDD and
% r, rD, rDD.  Remember that u+F(rD) < u  
bp = -(pDD + a*sin(p)) ./ (u + b*rD + c);
br = rDD ./(u + b*rD + c);

%returned values
bpMax = max(bp);
brMax = max(br);
% Do the plotting
subplot(2,1,1)
plot(t,bp)
legend(['b_p max is ',num2str(bpMax)])
title([num2str(bpMax/1.08*100),'% of the predicted val'])
subplot(2,1,2)
plot(t,br)
legend(['b_r max is ',num2str(brMax)])
title([num2str(brMax/198*100),'% of the predicted val'])

