
%% Formatting
clear all
close all

%% Read in the Data
t0 = importdata('xy.dat');
% t1 = importdata('t1.dat');
% t2 = importdata('t2.dat');
% t3 = importdata('t3.dat');
% t4 = importdata('t4.dat');
% t5 = importdata('t5.dat');

%% Create inputs for movify

tx = [t0(:, 2)]; 
ty = [t0(:, 3)];



%% Generate the movie?
figure
xlabel('AU')
ylabel('AU')
sz = ones(1, 1000);
sz = sz + 5;
j = 1;
i = 1;
while i<length(tx)
    hold off
    scatter(0, 0, 1)
    hold on
    scatter(tx(i), ty(i), 100, 'k', 'filled')
    scatter(tx(i+1), ty(i+1), 50, 'g', 'filled')
    scatter(tx(i+2), ty(i+2), 70, 'm', 'filled')
    scatter(tx((i+3):(i+1002)), ty((i+3):(i+1002)), sz, 'b', 'filled');
    ylim manual
    xlim manual
    ylim([-15 15]);
    xlim([-15 15]);
    M(j) = getframe;
    i = i+10030;
    j = j+1;
end


video=VideoWriter('fast_orbitz','Motion JPEG 2000');
video.FrameRate=60;
open(video); 
writeVideo(video,M);

