public class ProducerConsumer{
	public static void main(String[] args){
		StackBasket s = new StackBasket();
		Producer p = new Producer();
		Consumer c1 = new Consumer();

		Thread tp = new Thread(p);
		Thread tc1 = new Thread(c1);

		tp.start();
		tc1.start();
	}
}
class Item{
	int val;
	Item(int val){
		this.val = val;
	}
}

class StackBasket{
	Item arr[] = new Item[10];
	int idx = 0;
	public synchronized void push(Item it){
		try{
			while(idx == arr.length){
				System.out.println("enough!");
				this.wait();
			}
			this.notify();
		}catch(InterruptedException e){
			e.printStackTrace();
		}catch(IllegalMonitorStateException e){
			e.printStackTrace();
		}

		arr[idx++] = it;
	}

	public synchronized Item pop(){
		try{
			while(idx == 0){
				System.out.println("wait, no Item!");
				this.wait()
			}
			this.notify();
		}catch(InterruptedException e){
			e.printStackTrace();
		}catch(IllegalMonitorStateException e){
			e.printStackTrace();
		}
		idx--;
		return arr[idx];
	}
}

class Producer implements Runnable{
	StackBasket sb;
	Producer(StackBasket sb){
		this.sb = sb;
	}
	/*
	*	produce
	*/
	public void run(){
		for(int i = 0; i < 20; i++){
			Item it = new Item(i);
			sb.push(it);
			try{
				Thread.sleep((int) (Math.random() * 500));
			}catch(InterruptedException e){
				e.printStackTrace();
			}
		}
	}
}

class Consumer implements Runnable{
	StackBasket sb;
	Consumer(StackBasket sb){
		this.sb = sb;
	}

	public void run(){
		for(int i = 0; i < 200; i++){
			Item it = sb.pop();
			if(it == null){
				System.out.println("no item now, you need wait");
			}else{
				System.out.println("item " + it.val + "is consuming");
			}
			try{
				Thread.sleep((int)(Math.random()* 1000));
			}catch(InterruptedException e){
				e.printStackTrace();
			}

		}
	}
}