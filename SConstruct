srcs = ['neven.c']
srcs += Glob('Embedded/common/src/b_*Em/*.c')
srcs += Glob('FaceRecEm/common/src/b_FDSDK/*.c')

env = Environment()
env.Append(CPPPATH = ['Embedded/common/src/'])
env.Append(CCFLAGS = ['-O3', '-Depl_LINUX'])

neven_so = env.SharedLibrary('neven', srcs)

import os
prefix = '/usr/local'
env.Alias('install', env.Install(os.path.join(prefix, 'lib'), neven_so))
env.Alias('install', env.Install(os.path.join(prefix, 'include'), 'neven.h'))
env.Alias('install', env.Install(os.path.join(prefix, 'shared/neven/bmd'),
                     Glob('Embedded/common/data/APIEm/Modules/*.bmd')))

