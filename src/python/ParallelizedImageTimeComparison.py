import copy
from time import *
from readwritePPM import *
from multiprocessing import Pool
import timeit


def reduceColor(args):
    imageIn = args[0]
    factor = args[1]
    imageOut = args[2]
    print("Starting\t", factor)
    start = time()
    for y in range(len(imageIn)):
        row=[]
        for x in range(len(imageIn[y])):
            pixel=[]
            for c in range(len(imageIn[y][x])):
                pixel.append(int(imageIn[y][x][c]/factor)*factor)
            row.append(pixel)
            imageOut.append(row)
    print("Ending\t\t", factor, " time:", str(time()-start))
    # return imOut


def main():

    # set up list of lists of arguments for the reduceColor function
    imageData=readPPM("images/dog.ppm")
    argsIn=[]
    for x in range(1,16):
        factor = 2**x
        temp = imageData, factor, []
        argsIn.append(temp)

    parallelArgsIn = copy.deepcopy(argsIn)

    # single thread
    start = time()
    for x in range(len(argsIn)):
        reduceColor(argsIn[x])
    finish=time()
    print("Reduce color single thread: "+str(finish-start)+" seconds")

    #multi thread
    pool = Pool()
    start = time()
    pool.map(reduceColor, parallelArgsIn)
    finish = time()
    pool.close()

    print("Reduce color multi thread: "+str(finish-start)+" seconds")

main()

