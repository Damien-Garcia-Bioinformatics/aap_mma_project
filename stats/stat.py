#! /usr/bin/env python3

import pandas as pd
from matplotlib import pyplot as plt

df1 = pd.read_csv(r'score1.csv', sep=';')
df2 = pd.read_csv(r'score2.csv', sep=';')
df3 = pd.read_csv(r'score3.csv', sep=';')

df = pd.concat([df1, df2, df3], axis=0)

print(df)
df.plot(kind='scatter', x='proj_length', y='exec_time')
plt.savefig('lenVStime.jpg', format='jpeg')
#plt.show()
df.plot(kind='scatter', x='proj_length', y='score_g')
plt.savefig('lenVSsg.jpg', format='jpeg')
#plt.show()
df.plot(kind='scatter', x='proj_length', y='score_e')
plt.savefig('lenVSse.jpg', format='jpeg')
#plt.show()
df.plot(kind='scatter', x='proj_length', y='match_e')
plt.savefig('lenVSme.jpg', format='jpeg')
#plt.show()