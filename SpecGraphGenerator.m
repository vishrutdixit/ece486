
%[Mp_1, tr_1, ts_1] = StepResponseMetrics(y1(:,2),y1(:,1), 1, 4.86)

%[Mp_2, tr_2, ts_2] = StepResponseMetrics(ctrl2_wr_w,ctrl2_wr_t, 1, 1);
%[Mp_3, tr_3, ts_3] = StepResponseMetrics(ctrl3_wr_w,ctrl3_wr_t, 1, 1);
%[Mp_4, tr_4, ts_4] = StepResponseMetrics(y2d,tout2d, 1, 1);
%[Mp_5, tr_5, ts_5] = StepResponseMetrics(y2e,tout2e, 1, 1);



t = 0:.01:0.8;

y = step(gcg_cl,t)

StepResponseMetrics(y,t, 1, 1)

[Mp_1, tr_1, ts_1] = StepResponseMetrics(pdf4(1002:1502,3) - 3 ,pdf4(1002:1502,1), 1, 2)

%plot(pd2(:,1)-3,pd2(:,2))

