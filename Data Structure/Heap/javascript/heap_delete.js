function BinaryHeap(){
    let list = [];
    

    this.maxHeapify = (arr, n, i) => {
        let largest = i;
        let l = 2 * i + 1;
        let r = 2 * i + 2;

        if (l < n && arr[l] > arr[largest]) {
            largest = l; 
        }

        if (r < n && arr[r] > arr[largest]) {
            largest = r; 
        }

        if (largest != i) { 
            let temp = arr[i]; 
            arr[i] = arr[largest]; 
            arr[largest] = temp; 
            this.maxHeapify(arr, n, largest); 
        } 
    }
    

    this.insert = (num) => {
        const size = list.length;

        if(size === 0){
            list.push(num);
        }else{
            list.push(num);
            for (let i = parseInt(list.length / 2 - 1); i >= 0; i--) {
                this.maxHeapify(list, list.length, i); 
            }
        }
    }
    

    this.delete = (num) => {
        const size = list.length;
        let i;
        for(i = 0; i < size; i++){
            if(list[i] === num){
                break;
            }
        }
        [list[i], list[size - 1]] = [list[size - 1], list[i]];
        list.splice(size - 1);
        for (let i = parseInt(list.length / 2 - 1); i >= 0; i--) {
            this.maxHeapify(list, list.length, i); 
        }
    }
    
    this.findMax = () => list[0];
    
    this.deleteMax = () => {
        this.delete(list[0]);
    }
    
    this.extractMax = () => {
        const max = list[0];
        this.delete(max);
        return max;
    }
    
    this.size = () => list.length;
    this.isEmpty = () => list.length === 0;
    this.getList = () => list;
    }



var heap = new BinaryHeap();
heap.insert(3);
heap.insert(4);
heap.insert(9);
heap.insert(5);
heap.insert(2);
heap.insert(1);

console.log("Max-Heap: ");
console.log(heap.getList());


console.log("After deleting an element: ");
heap.delete(9);
console.log(heap.getList());

