// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

package ch.protonmail.android.utils.nativelib;

import java.util.concurrent.atomic.AtomicBoolean;
import javax.annotation.CheckForNull;
import javax.annotation.Nonnull;

public abstract class IPMCustom {
    @Nonnull
    public abstract String getValue();

    @Nonnull
    public abstract String getType();

    @Nonnull
    public abstract String getGroup();

    @CheckForNull
    public static native IPMCustom createInstance(@Nonnull String type, @Nonnull String value);

    private static final class CppProxy extends IPMCustom
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            destroy();
            super.finalize();
        }

        @Override
        public String getValue()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getValue(this.nativeRef);
        }
        private native String native_getValue(long _nativeRef);

        @Override
        public String getType()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getType(this.nativeRef);
        }
        private native String native_getType(long _nativeRef);

        @Override
        public String getGroup()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getGroup(this.nativeRef);
        }
        private native String native_getGroup(long _nativeRef);
    }
}
