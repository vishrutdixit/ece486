close all

time = Elect(:,1);
voltage = Elect(:,2);

Rs = 2.5;
Ra = 3.3;
Vss = 0.425;
%Vss = (Rs*1)/(Rs+Ra)

out = log(Vss - voltage);

coeffs = polyfit(time, out, 1)

y_fitted = coeffs(1)*time + coeffs(2);

idx = find(time > .0005, 1, 'first')
idx = idx-1;

hold on
plot(time(1:idx), out(1:idx))
plot(time(1:idx), y_fitted(1:idx))
xlabel('time (s)');
ylabel('$ln(V_{ss} - V_{0}(t))$', 'interpreter', 'latex');
title('Time vs. Voltage Linear Fit');
legend('actual', 'linear fit');

La = (Vss*(Rs+Ra))/Rs
Te = La/(Ra+Rs)

