%% Params
K = .1;

%% Plot

t = 0:.005:5;

%figure(1), hold on, grid on
%plot(t,ctrl_100p);
%plot(t,ctrl_100n);
%plot(t,ctrl_50p);
%plot(t,ctrl_50n);

pos_i = [50 100 150 200];
pos_val = [1.25 1.85 2.49 3.14];

neg_i = [-50 -100 -150 -200];
neg_val = [-1.33 -1.93 -2.58 -3.25];

coeffs = polyfit(pos_i,pos_val,1); 

b_pos = coeffs(1)
c_pos = coeffs(2)

coeffs = polyfit(neg_i,neg_val,1);

b_neg = coeffs(1)
c_neg = coeffs(2)

%y = coeffs(1)*pos_i + coeffs(2);

%figure(2), hold on, grid on
%subplot(1,2,1), plot(pos_i, pos_val);
%subplot(1,2,2), plot(pos_i, y);


neg_i = [-50 -100 -150 -200];
neg_val = [-1.33 -1.93 -2.58 -3.25];

