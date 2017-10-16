%load('./prelab4');
close all

K_tach = 0.0304;

time = Iner6(:,1);
V_tach = Iner6(:,2);
w = V_tach / K_tach;

%figure(1), plot(time, w);

offset_idx = find(time > 0.8, 1, 'first')

time  = time(offset_idx:1000)
w = w(offset_idx:1000)

b = 2.543e-5;
c = 0.0075;

Wss = -c/b;

out = log(w - Wss);

%plot(time, w);

%idx = find(time > .45, 1, 'first');
%idx = idx-1;

coeffs = polyfit(time, out, 1);

y_fitted = coeffs(1)*time + coeffs(2);

hold on
plot(time, out)
plot(time, y_fitted)
xlabel('time (s)');
ylabel('$ln(W(t) - W_{ss})$', 'interpreter', 'latex');
title('Time vs. Angular Velocity Linear Fit');
legend('actual', 'linear fit');

J = -b/coeffs(1)



