clc
clear all
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%first split
data=xlsread('Exam1_1.xlsx');
EE_015 = data(:,[1 2]);
IE_015 = data(:,[1 3]);
RK2_015 = data(:,[1 4]);
RK4_015 = data(:,[1 5]);
f = @(x) cos(0.5*sqrt(327/5)*x);
t_true_015 = linspace(0,6,6/0.15);
y_true_015 = f(t_true_015);

figure(1)
plot(t_true_015,y_true_015,'MarkerSize',20);
hold on
plot(EE_015(:,1),EE_015(:,2),'MarkerSize',20);
plot(IE_015(:,1),IE_015(:,2),'MarkerSize',20);
plot(RK2_015(:,1),RK2_015(:,2),'MarkerSize',20);
plot(RK4_015(:,1),RK4_015(:,2),'MarkerSize',20);
legend('Exact','EE','IE','RK2','RK4');
axis([0 6 -3 1.5])
xlabel('t')
ylabel('θ(t)')
legend('Exact, h=0.15','Explicit Euler, h=0.15','Implicit Euler, h=0.15','Second-Order Runge-Kutta, h=0.15','Fourth-Order Runge-Kutta, h=0.15','Location','SouthWest')

EE_05 = data(:,[6 7]);
IE_05 = data(:,[6 8]);
RK2_05 = data(:,[6 9]);
RK4_05 = data(:,[6 10]);
t_true_05 = linspace(0,6,6/0.5);
y_true_05 = f(t_true_05);

figure(2)
plot(t_true_015,y_true_015,'MarkerSize',20);
hold on
plot(EE_05(:,1),EE_05(:,2),'MarkerSize',20);
plot(IE_05(:,1),IE_05(:,2),'MarkerSize',20);
plot(RK2_05(:,1),RK2_05(:,2),'MarkerSize',20);
plot(RK4_05(:,1),RK4_05(:,2),'MarkerSize',20);
legend('Exact','EE','IE','RK2','RK4');
axis([0 6 -3 2])
xlabel('t')
ylabel('θ(t)')
legend('Exact, h=0.5','Explicit Euler, h=0.5','Implicit Euler, h=0.5','Second-Order Runge-Kutta, h=0.5','Fourth-Order Runge-Kutta, h=0.5','Location','SouthWest')

EE_1 = data(:,[11 12]);
IE_1 = data(:,[11 13]);
RK2_1 = data(:,[11 14]);
RK4_1 = data(:,[11 15]);
t_true_1 = linspace(0,6,6/1);
y_true_1 = f(t_true_1);

figure(3)
plot(t_true_1,y_true_1,'MarkerSize',20);
hold on
plot(EE_1(:,1),EE_1(:,2),'MarkerSize',20);
plot(IE_1(:,1),IE_1(:,2),'MarkerSize',20);
plot(RK2_1(:,1),RK2_1(:,2),'MarkerSize',20);
plot(RK4_1(:,1),RK4_1(:,2),'MarkerSize',20);
legend('Exact','EE','IE','RK2','RK4');
axis([0 6 -6 4.5])
xlabel('t')
ylabel('θ(t)')
legend('Exact, h=1.0','Explicit Euler, h=1.0','Implicit Euler, h=1.0','Second-Order Runge-Kutta, h=1.0','Fourth-Order Runge-Kutta, h=1.0','Location','SouthWest')