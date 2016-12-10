xy = dlmread('xy.dat');
figure()
plot(xy(1:501,1),xy(1:501,3),'.')
hold on
plot(xy(502:end,1),xy(502:end,3),'.')


hold off

figure()
scatter3(xy(1:501,1),xy(1:501,3),xy(1:501,5))
hold on 
scatter3(xy(502:end,1),xy(502:end,3),xy(502:end,5))
hold off 

