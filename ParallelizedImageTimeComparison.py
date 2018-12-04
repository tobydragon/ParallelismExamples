import copy
from time import *
from readwritePPM import *
from multiprocessing import Pool


def reduceColor(info):
    image=info[0]
    factor=info[1]
    name=info[2]
    imOut=info[3]
    print("Starting\t", factor)
    start = time()
    # make it happen 5 times to increase task time
    for a in range(5):
        for y in range(len(image)):
            row=[]
            for x in range(len(image[y])):
                pixel=[]
                for c in range(len(image[y][x])):
                    pixel.append(int(image[y][x][c]/factor)*factor)
                row.append(pixel)
            imOut.append(row)
    print("Ending\t\t", factor, " time:", str(time()-start))


def main():

    # set up list of lists of arguments for the reduceColor function
    im=readPPM("images/dog.ppm")
    argsIn=[]
    for x in range(1,4):
        factor=2**x
        name="reduceColor{:03}.ppm".format(factor)
        temp=[im,factor,name, []]
        argsIn.append(temp)

    parallelArgsIn = copy.deepcopy(argsIn)

    # single thread
    start=time()
    for x in range(len(argsIn)):
        reduceColor(argsIn[x])
    finish=time()
    print("Reduce color single thread: "+str(finish-start)+" seconds")

    #multi thread

    pool=Pool(3)
    start=time()
    pool.map(reduceColor, parallelArgsIn)
    finish=time()
    pool.close()

    print("Reduce color multi thread: "+str(finish-start)+" seconds")

main()
