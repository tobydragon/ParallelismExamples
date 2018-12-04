import urllib.request
from multiprocessing.dummy import Pool as ThreadPool
from time import *


urls = [
  'http://www.python.org',
  'http://www.python.org/about/',
  'http://www.onlamp.com/pub/a/python/2003/04/17/metaclasses.html',
  'http://www.python.org/doc/',
  'http://www.python.org/download/',
  'http://www.python.org/getit/',
  'http://www.python.org/community/',
  'https://wiki.python.org/moin/',
  'http://planet.python.org/',
  'https://wiki.python.org/moin/LocalUserGroups',
  'http://www.python.org/psf/',
  'http://docs.python.org/devguide/',
  'http://www.python.org/community/awards/'
  # etc..
  ]

start = time()
results = []
for url in urls:
    results.append(urllib.request.urlopen(url))
elapsed=time()-start
print(elapsed)

# Make the Pool of workers
pool = ThreadPool(4)
# Open the urls in their own threads
# and return the results
start = time()
results = pool.map(urllib.request.urlopen, urls)
pool.close()
#close the pool and wait for the work to finish
pool.close()
pool.join()
elapsed=time()-start
print(elapsed)