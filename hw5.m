%Question 3
% Explicit Euler
%% Analytic solution
%f = @(x,t) 1-(10*(x-0.08*t))^2; %y = 1-[10(x-0.08t)-1]^2
%f1 = @(x) 1-(10*x-1)^2; %y(t = 0) = 1-(10x-1)^2, 0<=x<=0.2
%f2 = @(x) 0*x; %y(t = 0) = 0, 0.2<x<=1
%t_true = linspace(0.01,8,100);
%x_true = linspace(0,1,100);
%x_true_1 = linspace(0,0.2,20);
%x_true_2 = linspace(0,0.8,80);
%y_true = f(t_true,x_true);
%y_true_1 = f(x_true_1);
%y_true_2 = f(x_true_2);

%% Numerical solution for deta x = 0.01, t = 0;
h = 0.01;
y1(1) = 0;
x1(1) = 0;
i = 1;
if (x1(i)<=0.2)
    y1(i+1) = y1(i) - 200*x1(i)*h+20*h;
    x1(i+1) = x1(i) + h;
    i = i + 1;
end
if (x1(i)<=1)
    y1(i+1) = 0;
    x1(i+1) = x1(i) + h;
    i = i + 1;
end

%% exact solution for deta x = 0.01, deta t = 0.08;
y2(1) = 0;
h21 = 0.01;%deta x
h22 = 0.0799;%deta t
x2(1) = 0;
x2(2) = 0.01;
t2(1) = 0.01;
t2(2) = 0.0899;
i = 2;
if ((x2(i)-0.08*t2(i)) <= 0.2 && (x2(i)-0.08*t2(i)) >= 0 )
    x2(i+1) = x2(i) + h21;
    t2(i+1) = t2(i) + h22;
    y2(i+1) = (h22/(h21^2))*(-100*((x2(i+1))^2-2*(x2(i))^2+(x2(i-1))^2)+0.64*((t2(i+1))^2-2*(t2(i))^2+(t2(i-1))^2)-20*(x2(i+1)-2*x2(i)+x2(i-1))+1.6*(t2(i+1)-2*t2(i)+t2(i-1))-16*(x2(i+1)*t2(i+1)-2*x2(i)*t2(i)+x2(i-1)*t2(i-1)));
    i = i + 1;
end

%% Plot explicit solutions
figure(1); clf;
%plot(t_true,y_true)
%plot(x_true,y_true)
%plot(x_true_1,y_true_2)
%plot(x_true_2,y_true_2)
plot(x1,y1)
hold on
plot(x2,y2)
plot(t2,y2)
%plot(t1,y1,'k.--','MarkerSize',20)
%plot(t2,y2,'ro--','MarkerSize',10)
%axis([0 20 -1.5 2])
xlabel('t')
ylabel('y(t)')
legend('Numerical solution','exact solution, x','exact solution, y','NorthWest')
