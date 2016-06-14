interface Discount{
    public double calculate(double price);       
}
class StudentDiscrount implements Discount{
    public double calculate(double price){   
    	return price*0.8;  
    }
}
class ChildrenDiscrount implements Discount{
    public double calculate(double price){   
    	return price-10;   
    }
}
class VIPDiscrount implements Discount{
    public double calculate(double price){   
        System.out.println("增加积分!");
        return price*0.5;
    }
}

class MovieTicket{     
    private double price;
    private Discount discount;
    public void setPrice(double price){    
    	this.price=price;  
    }
    public void setDiscount(Discount discount){
    	this.discount=  discount;
    }
    public double getPrice(){ 
    	return discount.calculate(price);
    }
}

class Client{      
	public static void main(String args[]){
        MovieTicket mt = new MovieTicket();
        mt.setPrice(50);
        double currentPrice;
        Discount obj;
        obj = new StudentDiscrount();
        mt.setDiscount(obj);
        currentPrice = mt.getPrice();
        System.out.println("折后价："+currentPrice);
        obj = new VIPDiscrount();
        mt.setDiscount(obj);
        currentPrice = mt.getPrice();
        System.out.println("折后价："+currentPrice);
    }
}


