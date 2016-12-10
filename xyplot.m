xy = dlmread('xy.dat');
figure()
plot(xy(:,1),xy(:,3),'.')

figure()
scatter3(xy(:,1),xy(:,3),xy(:,5))


