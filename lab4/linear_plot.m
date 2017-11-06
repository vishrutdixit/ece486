load('./data/linear_voltage');

figure(1),hold on
plot(t1,y1)
plot(t2,y2)
plot(t3,y3)
plot(t4,y4)
plot(t5,y5)
plot(t6,y6)
title('Linear Regions for Voltage')
xlabel('time (s)');
ylabel('$ln(V_{ss} - V_{0}(t))$', 'interpreter', 'latex');

%load('./data/linear_iner');


%figure(2), hold on
%plot(t1,y1)
%plot(t2,y2)
%plot(t3,y3)
%plot(t4,y4)
%plot(t5,y5)
%plot(t6,y6)
%title('Linear Regions for Angular Velocity')
%xlabel('time (s)');
%ylabel('$ln(W(t) - W_{ss})$', 'interpreter', 'latex');


