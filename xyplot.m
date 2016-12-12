xy = dlmread('xy.dat');
figure()
plot(xy(1:500,1),xy(1:500,3),'.')
hold on
plot(xy(501:end,1),xy(501:end,3),'.')
xlabel('x');
ylabel('y');


hold off

figure()
scatter3(xy(1:500,1),xy(1:500,3),xy(1:500,5))
hold on 
scatter3(xy(501:end,1),xy(501:end,3),xy(501:end,5))
xlabel('x');
ylabel('y');
zlabel('z');
hold off 

