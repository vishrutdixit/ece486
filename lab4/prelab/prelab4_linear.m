%load('..\data\lab4');
close all

time = Elect6(:,1);
voltage = Elect6(:,2);

offset_idx = find(time > 1e-3, 1, 'first')

time  = time(offset_idx:1000)
voltage = voltage(offset_idx:1000)

Rs = 2.524;
Ra = 5.0773;

Vss = max(voltage)

out = log(Vss - voltage);

idx = find(time > 1.5e-3, 1, 'first')
idx = idx-1

t6 = time(1:idx);
y6 = out(1:idx);

coeffs = polyfit(time(1:idx), out(1:idx), 1)

y_fitted = coeffs(1)*time + coeffs(2);

hold on
plot(time(1:idx), out(1:idx))
plot(time(1:idx), y_fitted(1:idx))
xlabel('time (s)');
ylabel('$ln(V_{ss} - V_{0}(t))$', 'interpreter', 'latex');
title('Time vs. Voltage Linear Fit');
legend('actual', 'linear fit');

Te = -1/coeffs(1)
La = Te*(Ra+Rs)