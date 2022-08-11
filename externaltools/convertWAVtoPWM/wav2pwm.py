# -*- coding: utf-8 -*-
"""
Created on Tue May  3 00:38:42 2022

@author: bemar
"""
import numpy as np
import matplotlib.pyplot as plt
import soundfile as sf
import samplerate
soundfile = '/home/benjencabreram/Documents/git-repos/.venv-playnativa/playnativa-memorice/externaltools/convertWAVtoPWM/tucuquereFiltrado.wav'
text_path = '/home/benjencabreram/Documents/git-repos/.venv-playnativa/playnativa-memorice/audio'
###
data_in, datasamplerate = sf.read(soundfile)
# This means stereo so extract one channel 0
if len(data_in.shape)>1:
    data_in = data_in[:,0]
# plt.plot(data_in)
# plt.ylabel(soundfile)
# plt.show()
###

###
converter = 'sinc_best'  # or 'sinc_fastest', ...
desired_sample_rate = 11000.0
ratio = desired_sample_rate/datasamplerate
data_out = samplerate.resample(data_in, ratio, converter)
print(data_out)
maxValue = max(data_out)
minValue = min(data_out)
print("length", len(data_out))
print("max value", max(data_out))
print("min value", min(data_out))
vrange = (maxValue - minValue) 
print("value range", vrange)
###

###
data_pwm = []
m68code = "/*    File "+soundfile+ "\r\n *    Sample rate "+str(int(desired_sample_rate)) +" Hz\r\n */\r\n"
m68code += "#define WAV_DATA_LENGTH "+str(len(data_out))+" \r\n\r\n"
m68code += "uint8_t WAV_DATA[] = {\r\n    "
maxitemsperline = 16
itemsonline = maxitemsperline
firstvalue = 0
lastvalue = 0
with open(text_path, 'w') as f:
    f.write('{')
    f.write('\r\n')
    for v in data_out:
        # scale v to between 0 and 1
        isin = (v-minValue)/vrange   
        v =  int((isin * 255))
        vstr = str(v)
        if (firstvalue==0):
            firstvalue= v
        lastvalue = v
        m68code+=vstr
                
        itemsonline-=1
        if (itemsonline>0):
            m68code+=','
        else:
            itemsonline = maxitemsperline
            m68code+=',\r\n    '
        f.write('       MP_ROM_INT(')
        f.write(vstr)
        f.write('),')
        f.write('\r\n')
    f.write('},')
# keep track of first and last values to avoid
# blip when the loop restarts.. make the end value
# the average of the first and last. 
end_value = int( (firstvalue + lastvalue) / 2)
m68code+=str(end_value)+'    \r\n};'
#print(m68code)
###

np.savetxt("audio", data_pwm, newline="\n")