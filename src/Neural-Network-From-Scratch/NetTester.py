import mnist_loader
import nnScratch


trainingData, validationData, testData = \
mnist_loader.load_data_wrapper()

net = nnScratch.Network([784, 10])

#net.SGD(trainingData, 30, 10, 3.0, testData=testData)
net.SGD(trainingData, 30, 10, 3.0, test_data=testData)









