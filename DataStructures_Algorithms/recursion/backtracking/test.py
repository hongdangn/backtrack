import torch

# x = torch.tensor([2.])
x = torch.tensor([1., 2., 3.], requires_grad = True)
print(x/max(x))

