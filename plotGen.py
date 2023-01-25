#! /usr/bin/env python3

import pandas as pd
from matplotlib import pyplot as plt

df1 = pd.read_csv(r'datasets/data1/scores.csv', sep = ';')
df2 = pd.read_csv(r'datasets/data2/scores.csv', sep = ';')
df3 = pd.read_csv(r'datasets/data3/scores.csv', sep = ';')
df4 = pd.read_csv(r'datasets/data4/scores.csv', sep = ';')

df = pd.concat([df1, df2, df3, df4], axis=0)

df['se/len'] = df['score_e']/df['proj_length']
df['me/len'] = df['match_e']/df['proj_length']

print(df)

df.plot(kind='scatter', x='proj_length', y='exec_time')
plt.savefig('report/plots/lenVStime.jpg', format='jpeg')

df.plot(kind='scatter', x='proj_length', y='score_g')
plt.savefig('report/plots/lenVSsg.jpg', format='jpeg')

df.plot(kind='scatter', x='proj_length', y='score_e')
plt.savefig('report/plots/lenVSse.jpg', format='jpeg')

df.plot(kind='scatter', x='proj_length', y='match_e')
plt.savefig('report/plots/lenVSme.jpg', format='jpeg')

df.plot(kind='scatter', x='proj_length', y='se/len')
plt.savefig('report/plots/lenVSselen.jpg', format='jpeg')

df.plot(kind='scatter', x='proj_length', y='me/len')
plt.savefig('report/plots/lenVSmelen.jpg', format='jpeg')

df.plot(kind='scatter', x='proj_length', y='general_score')
plt.savefig('report/plots/lenVSgen.jpg', format='jpeg')