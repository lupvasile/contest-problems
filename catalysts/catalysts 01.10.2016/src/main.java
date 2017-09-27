import java.io.File;
import java.util.Random;
import java.util.Scanner;

import org.jfugue.midi.MidiFileManager;
import org.jfugue.pattern.Pattern;
import org.jfugue.pattern.PatternProducer;
import org.jfugue.player.Player;
import org.jfugue.provider.ChordProvider;
import org.jfugue.provider.ChordProviderFactory;
import org.jfugue.realtime.RealtimePlayer;
import org.jfugue.rhythm.Rhythm;
import org.jfugue.theory.Chord;
import org.jfugue.theory.ChordProgression;
import org.jfugue.theory.Note;

import javax.sound.midi.MidiUnavailableException;

public class main {

    static String message;

    static void Print() {
        System.out.println(message);
    }

    public static void main(String[] args) {
        int tempo = 100;

        Pattern song = new Pattern();


        Pattern verseCover = new Pattern("Rw | C4majww- A3minww- F3majw- G3majw- " +
                "C4majww- A3minww- F3majw- G3majw- ")
                .setInstrument("Flute")
                .setTempo(tempo)
                .setVoice(0);



        Pattern chorusCover = new Pattern("Rw C4majww A3minww F3majw G3majw C4majw")
                .setInstrument(49)
                .setTempo(tempo)
                .setVoice(0);

        Pattern chorusSolo = new Pattern("Rh. C5i G5h. C5i A5i G5hi B5i A5s A5i. G5i G5hi C5i A5i G5hi B5i A5s A5i. G5i G5h. G5i A5h. C5i C5i G5h.")
                .setInstrument(29)
                .setTempo(tempo)
                .setVoice(1);
        Pattern chorusSolo2 = new Pattern("Rw8 Rh. C5i G5h. C5i A5i G5hi B5i A5s A5i. G5i G5hi C5i A5i G5hi B5i A5s A5i. G5i G5h. G5i A5h. C5i C5i G5h. Rw8q Rh. C5i G5h. C5i A5i G5hi B5i A5s A5i. G5i G5hi C5i A5i G5hi B5i A5s A5i. G5i G5h. G5i A5h. C5i C5i G5w")
                .setInstrument("Piano")
                .setTempo(tempo)
                .setVoice(3);

        Pattern chorusBass = new Pattern("Rw9 C3s Ri C3s Ri C3hi C3s Ri C3s Ri C3hi A2s Ri A2s Ri A2hi A2s Ri A2s Ri A2hi F2s Ri F2s Ri F2hi G2s Ri G2s Ri G2hi C3s Ri C3s Ri C3hi")
                .setInstrument("ELECTRIC_BASS_FINGER")
                .setTempo(tempo)
                .setVoice(2);

        Pattern bridgeCover = new Pattern("Rw17 G3majwh. Eminww C4majw D4majw G3majw")
                .setInstrument(49)
                .setTempo(tempo)
                .setVoice(5);
        Pattern bridge = new Pattern("Rw17 B6q C7i B6q. A6i G6h.i B6i B6q C7i B6q. A6i G6h.i Rq B6q C7i B6q. G6i A6h. D6i D6i G6wi")
                .setInstrument("OVERDRIVEN_GUITAR")
                .setTempo(tempo)
                .setVoice(4);
        Pattern bridge2 = new Pattern("Rw17 D6q E6i D6q. C6i B5h.i D6i D6q E6i D6q. C6i B5h.i Rq D6q E6i D6q. B5i C6h. F#5i F#5i B5wi")
                .setInstrument("OVERDRIVEN_GUITAR")
                .setTempo(tempo)
                .setVoice(6);


        int m = 8, n = 0;
        Rhythm rhythm = new Rhythm()
                .addLayer(new String(new char[m]).replace("\0", "........") + new String(new char[4]).replace("\0", "O..oO...O..oOO..") + new String(new char[n]).replace("\0", "........") + new String(new char[4]).replace("\0", "................"))
                .addLayer(new String(new char[m]).replace("\0", "........") + new String(new char[4]).replace("\0", "..S...S...S...S.") + new String(new char[n]).replace("\0", "........") + new String(new char[4]).replace("\0", "................"))
                .addLayer(new String(new char[m]).replace("\0", "........") + new String(new char[4]).replace("\0", "````````````````") + new String(new char[n]).replace("\0", "........") + new String(new char[4]).replace("\0", "................"))
                .addLayer(new String(new char[m]).replace("\0", "........") + new String(new char[4]).replace("\0", "...............+") + new String(new char[n]).replace("\0", "........") + new String(new char[4]).replace("\0", "................"));



        //song.add(verseCover);
        song.add(chorusCover.repeat(2));
        song.add(chorusSolo);
        song.add(chorusSolo2);
        song.add(chorusBass);
        song.add(bridge);
        song.add(bridge2);
        song.add(bridgeCover);
//        song.add(
//                new ChordProgression("I IV V")
//                        .distribute("7%6")
//                        .allChordsAs("$0 $0 $1 $1 $2 $1 $0")
//                        .eachChordAs("$0i $1ia80 $2ia80 $3ia80 $4i $3ia80 $2ia80 $1ia80")
        //new Rhythm().addLayer(new String(new char[0]).replace("\0", "................") + new String(new char[8]).replace("\0", "OxOXOxOXOxOXOxOX"))
//        );
        song.add(rhythm.getPattern().setTempo(tempo));
        //song.add(verseSolo);
        //song.add(verseRhythm);


        new Player().play(song);
    }
}