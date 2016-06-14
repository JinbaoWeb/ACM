import java.util.ArrayList;
interface Subject {
	public void registerObserver(Observer o);
	public void removeObserver(Observer o);
	public void notifyObservers();
}
interface Observer {
	public void update(float temp, float humidity, float pressure);
}
interface DisplayElement{
	public void display();
}
class WeatherData implements Subject {
    private ArrayList observers;
    private float temperature, humidity, pressure;
    public WeatherData(){  
      	observers = new ArrayList();  
    }
    public void registerObserver(Observer o){
        observers.add(o);
    }
    public void removeObserver(Observer o){
        int i = observers.indexOf(o);
        if (i >= 0) {observers.remove(i);}
    }
    public void notifyObservers() {
        for (int i = 0; i < observers.size(); i++) {
            Observer observer = (Observer)observers.get(i);
			observer.update(temperature, humidity, pressure);
        }
    }
    public void measurementsChanged(){
    	notifyObservers();
    }
    public void setMeasurements(float temperature,float humidity,float pressure){
    	this.temperature=temperature;
    	this.humidity=humidity;
    	this.pressure=pressure;
    	measurementsChanged();
    }
}
class CurrentConditionsDisplay implements Observer,DisplayElement{
	private float temperature;
	private float humidity;
	private Subject weatherData;
    public CurrentConditionsDisplay(Subject weatherData) {
		this.weatherData = weatherData;
		weatherData.registerObserver(this);
    }
    public void update(float temperature, float humidity, float pressure) {
		this.temperature = temperature;
		this.humidity = humidity;
		display();
    }
    public void display() {
        System.out.println("Current conditions: " + temperature + "F degrees and " + humidity + "% humidity");
    }

}
public class WeatherStation {
    public static void main(String[] args) {
        WeatherData weatherData = new WeatherData();
        CurrentConditionsDisplay currentDisplay = new CurrentConditionsDisplay(weatherData);
        //StatisticsDisplay statisticsDisplay = new StatisticsDisplay(weatherData);
        //ForecastDisplay forecastDisplay = new ForecastDisplay(weatherData);

        weatherData.setMeasurements(80, 65, 30.4f);
        //weatherData.setMeasurements(82, 70, 29.2f);
       // weatherData.setMeasurements(78, 90, 29.2f);
    }
}

