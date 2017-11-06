<<<<<<< HEAD
close all
s = tf('s');

as = [.01 0.01 1 10 100];

Mps = zeros(1,size(as,2));
Mrs = zeros(1,size(as,2));

idx = 0;
for a = as
    sys = ((s/a) + 1) /(s^2 + s + 1);
    idx = idx+1;
    t = 0:.1:20;
    %figure(idx), step(sys,t)
    [Mp, tr, ts] = StepResponseMetrics(step(sys,t), t, 1, 1);
     Mps(idx) = Mp;
     Mr = getPeakGain(sys);
     Mrs(idx) = Mr;
     %bode(sys)
end

disp(Mps)
disp(Mrs)

=======
s = tf('s');

%% Q1

g = 
>>>>>>> 8a08db7c19b526b234ae8c5639da3749d63c1eb7
