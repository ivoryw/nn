# nn
A framework for building neural network graphs

## Usage
Design the neural network object you want to use from the `nn::Net` base object.
Create the forward feed function using the `autodiff::var` for variables and Parameter for parameters.
Prebuilt layers with parameters are available.
```C++
class Network : public nn::Net{
public:
    Model() : nn::Net(), fc1(10, 5, this), fc2(5, 1, this){}
    
    nn::fc fc1, fc2;
    autodiff::var forward(autodiff::var& x){
        auto y = fc1(x);
        auto z = fc2(y);
        return z;
    }
};
```

After initialization the network is registered with an optimizer which has access to the parameters and their gradients.
```C++
Network net;
opt::GD optim(net.params);
```	

Training is performed using the `forward(x)` method, and backpropigation using `backwardProp(loss)`.
Optimization is then performed using the `step()` method.
```C++
auto output = net.forward(x);
loss.softmax(output, targets);
net.backwardProp(loss);
opt.step();
```
