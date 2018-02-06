[Mp_1, tr_1, ts_1] = StepResponseMetrics(y2a,tout2a, 1, 2)
[Mp, tr, ts] = StepResponseMetrics(y(:,1),tout, 1, 2);
[Mp_3, tr_3, ts_3] = StepResponseMetrics(y2c,tout2c, 1, 2);
[Mp_4, tr_4, ts_4] = StepResponseMetrics(y2d,tout2d, 1, 2);
[Mp_5, tr_5, ts_5] = StepResponseMetrics(y2e,tout2e, 1, 2);
[Mp_6, tr_6, ts_6] = StepResponseMetrics(y6(:,2),y6(:,1), 1, 2);
[Mp_7, tr_7, ts_7] = StepResponseMetrics(y7(:,2),y7(:,1), 1, 2);
[Mp_8, tr_8, ts_8] = StepResponseMetrics(y8(:,2),y8(:,1), 1, 2);


zeta = [-10:.1:10]
p1 = -zeta + sqrt((zeta.^2) - 1);
p2 = -zeta - sqrt((zeta.^2) - 1);

plot(zeta, p1, 'b')
hold on
grid on
plot(zeta, p2, 'g')
xlabel('\zeta');
ylabel('poles');
title('\zeta vs pole locations');
