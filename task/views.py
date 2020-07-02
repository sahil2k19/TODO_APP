from django.shortcuts import render, redirect
from .models import *
from .forms import *
# Create your views here.
def home(request):
    tasks = Task.objects.all()
    form = Taskform()
    if request.method == "POST":
        form = Taskform(request.POST)
        if form.is_valid:
            form.save()
            return redirect('/')
    context = {"form":form, "tasks":tasks}
    return render(request, "home.html", context)

def update(request, pk):
    task = Task.objects.get(id=pk)
    form = Taskform(instance=task)
    if request.method == 'POST':
        form = Taskform(request.POST, instance=task)
        if form.is_valid:
            form.save()
            return redirect('/')

    context = {"form":form, "task":task}
    return render(request, 'update.html', context)

def delete(request, pk):
    task = Task.objects.get(id=pk)
    
    if request.method == 'POST':
        task.delete()
        return redirect('/')
    context = {"task":task}
    return render(request, 'delete.html', context)
        
        



