
% This program analayze different voice 

% Amplitude Spectrum FFT Analaysis.

% after time of listening line say or play something.

% your data record and plot.

% Five different voice recording and after than plotting sequentially.

% You can say or play anything for a time you chose...



clear all

close all

clc

Fs=11025;  

Ts=1/Fs;

L=11025;

%time vector;

timevector=(0:L-1)*Ts;

t1=input(' time of listening t1: ');

%fprintf('\n Say or Play something... \n ');

recordy1=audiorecorder;
disp('Start speaking recorder 1.')
recordblocking(recordy1, t1);
disp('End of Recording 1.')
yI = getaudiodata(recordy1);
% calculating fft points;

nfft=2^nextpow2(L);

sig_fft=(fft(yI,nfft)/L);


f=Fs/2.*linspace(0,1,nfft/2+1);

%Voice 1

plot(f,2*abs(sig_fft(1:nfft/2+1)),'MarkerSize',4,'DisplayName',' Voice 1 ');

legend('-DynamicLegend');

hold all

fprintf('\n Voice 1 recorded and plotted...\n');

fprintf('\n');

pause(.5);

t2=input(' time of listening t2: ');

pause(.3);

%fprintf('\n Say or Play something... \n ');

recordy2=audiorecorder;
disp('Start speaking recorder 2.')
recordblocking(recordy2, t1);
disp('End of Recording 2.')
yII = getaudiodata(recordy2);


nfft=2^nextpow2(L);

sig_fft=(fft(yII,nfft)/L);

f=Fs/2.*linspace(0,1,nfft/2+1);

%Voice 2

plot(f,2*abs(sig_fft(1:nfft/2+1)),'MarkerSize',4,'DisplayName',' Voice 2 ');

fprintf('\n Voice 2 recorded and plotted...\n');

fprintf('\n');

pause(.5);

t3=input(' time of listening t3: ');

pause(.3);

%fprintf('\n  Say or Play something...\n ');

recordy3=audiorecorder;
disp('Start speaking recorder 3.')
recordblocking(recordy3, t1);
disp('End of Recording 3.')
yIII= getaudiodata(recordy3);

nfft=2^nextpow2(L);

sig_fft=(fft(yIII,nfft)/L);

f=Fs/2.*linspace(0,1,nfft/2+1);

%Voice 3

plot(f,2*abs(sig_fft(1:nfft/2+1)),'MarkerSize',4,'DisplayName',' Voice 3');

fprintf('\n Voice 3 recorded and plotted...\n');

fprintf('\n');

pause(.5);

t4=input(' time of listening t4: ');

pause(.3);

%fprintf('\n Say or Play something... \n ');

recordy4=audiorecorder;
disp('Start speaking recorder 4.')
recordblocking(recordy4, t1);
disp('End of Recording 4.')
yIV= getaudiodata(recordy4);

nfft=2^nextpow2(L);

sig_fft=(fft(yIV,nfft)/L);

f=Fs/2.*linspace(0,1,nfft/2+1);

%Voice 4

plot(f,2*abs(sig_fft(1:nfft/2+1)),'MarkerSize',4,'DisplayName',' Voice 4');

fprintf('\n Voice 4 recorded and plotted...\n');

fprintf('\n');

pause(.5);

t5=input('time of listening t5: ');

pause(.3);

%fprintf('\n Say or Play something... \n ');

recordy5=audiorecorder;
disp('Start speaking recorder 5.')
recordblocking(recordy5, t1);
disp('End of Recording 5.')
yV= getaudiodata(recordy5);

nfft=2^nextpow2(L);

sig_fft=(fft(yV,nfft)/L);

f=Fs/2.*linspace(0,1,nfft/2+1);

%Finally Voice 5

plot(f,2*abs(sig_fft(1:nfft/2+1)),'MarkerSize',4,'DisplayName',' Voice 5 ');

fprintf('\n Voice 5 recorded and plotted...\n');

fprintf('\n');

title(' Amplitude Spectrum of Different Voice ');

ylabel(' Y|f| ');

xlabel(' Frequency (Hz) ');

grid on

zoom on