SenReader.class: SenReader.java SenseMsg.java
	javac *.java

SenseMsg.java:
	mig java -target=null -java-classname=SenseMsg sensor.h SenseMsg -o $@

clean:
	rm -rf SenseMsg.java *.class
