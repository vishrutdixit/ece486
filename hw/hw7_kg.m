s = tf('s');

kd = 1/16*(s/.1+1)/(s/8+1)
g = 1/s^2
kdg = kd*g;
kdg_cl = kdg/(1+kdg)
t = 0:.1:20;
[Mp, tr, ts] = StepResponseMetrics(step(kdg_cl,t), t, 1, 1);
%margin(kdg)
bandwidth(kdg_cl)