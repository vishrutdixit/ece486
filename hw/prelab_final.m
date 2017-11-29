a = [ -18 16 8; -29 27 13; 10 -10 -4 ];
b = [ 1; -3; -2 ];
 
%% Part A  
poles = eig(a);
disp(poles);

%% Part B
x = a*b;
disp(x)
x = a*a*b;
disp(x)
c = [ 1  -82 -316 ;
     -3 -136 -670 ;
     -2   48  348 ]
rank(c)

%% Part C
p = [-2 -19 -38];
K = place(a,b,p);
disp(K);

%% Part D

eig(a-b*K)
