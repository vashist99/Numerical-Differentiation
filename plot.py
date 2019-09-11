#import matplotlib
import matplotlib.pyplot as plt
import numpy as np
#%matplotlib inline

list1 = [0.001,0.0015,0.0001,0.00015,0.00001,0.00001,0.0000015,0.0000001,0.00000015]
list2 =  [0.000154373,0.000148483,0.000165336,0.000164715,0.0001655,0.0001655,7.4334e-05,0.542265,0.321076]

list1 = np.array(list1)
list2 = np.array(list2)
plt.yscale('symlog',linthreshy=0.01)
plt.plot(list1,list2)
plt.show()